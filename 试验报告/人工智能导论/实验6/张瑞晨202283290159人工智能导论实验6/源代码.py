import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
import os

# 设置数据转换（将图像转换为Tensor，并进行标准化）
transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5,), (0.5,))])

epsilon = 0.3  # 对抗攻击的扰动大小
root_path = "/home/xclei/dataset"

# 打印当前路径的文件列表，确认数据集文件存在
print("当前路径文件列表:")
print(os.listdir(root_path))

# 加载MNIST数据集
trainset = datasets.MNIST(root=root_path, train=True, download=True, transform=transform)
trainloader = DataLoader(trainset, batch_size=64, shuffle=True)

testset = datasets.MNIST(root=root_path, train=False, download=True, transform=transform)
testloader = DataLoader(testset, batch_size=64, shuffle=False)

# 打印数据集的大小
print(f"Training set size: {len(trainset)}")
print(f"Test set size: {len(testset)}")

# 查看一批数据
data_iter = iter(trainloader)
images, labels = next(data_iter)
print(f"Batch shape: {images.shape}")
print(f"Labels: {labels}")

# 定义一个简单的卷积神经网络模型
class SimpleCNN(nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        self.conv1 = nn.Conv2d(1, 32, kernel_size=5)
        self.conv2 = nn.Conv2d(32, 64, kernel_size=5)
        self.fc1 = nn.Linear(1024, 128)
        self.fc2 = nn.Linear(128, 10)

    def forward(self, x):
        x = F.relu(F.max_pool2d(self.conv1(x), 2))
        x = F.relu(F.max_pool2d(self.conv2(x), 2))
        x = x.view(-1, 1024)  # Flatten the output of the last convolution layer
        x = F.relu(self.fc1(x))
        x = self.fc2(x)
        return x

# 自动选择设备（GPU 或 CPU）
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Using device: {device}")

# 创建模型实例并将其移动到选定设备
model = SimpleCNN().to(device)

# 创建优化器和损失函数
optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.9)
loss_fn = nn.CrossEntropyLoss()

# FGSM攻击函数
def fgsm_attack(model, loss_fn, images, labels, epsilon):
    images.requires_grad = True  # 设置需要计算梯度
    outputs = model(images)
    loss = loss_fn(outputs, labels)
    model.zero_grad()
    loss.backward()  # 反向传播计算梯度
    data_grad = images.grad.data
    perturbed_image = images + epsilon * data_grad.sign()  # 生成对抗样本
    return perturbed_image

# 训练函数
def train(model, trainloader, optimizer, loss_fn, epochs):
    model.train()
    train_losses = []
    train_accuracies = []
    for epoch in range(epochs):
        running_loss = 0.0
        correct = 0
        total = 0
        for i, (images, labels) in enumerate(trainloader):
            images, labels = images.to(device), labels.to(device)
            optimizer.zero_grad()
            outputs = model(images)
            loss = loss_fn(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

        train_losses.append(running_loss / len(trainloader))
        train_accuracies.append(100 * correct / total)
        print(f"Epoch {epoch+1}, Loss: {running_loss/len(trainloader):.4f}, Accuracy: {100 * correct / total:.2f}%")
    return train_losses, train_accuracies

# 评估模型性能
def evaluate(model, testloader):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for images, labels in testloader:
            images, labels = images.to(device), labels.to(device)
            outputs = model(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    accuracy = 100 * correct / total
    print(f'Accuracy on test set: {accuracy:.2f}%')
    return accuracy

# 可视化原始图像和对抗样本
def visualize_attack(model, testloader, epsilon):
    model.eval()
    data_iter = iter(testloader)
    images, labels = next(data_iter)
    images, labels = images.to(device), labels.to(device)

    # 生成对抗样本
    perturbed_images = fgsm_attack(model, loss_fn, images, labels, epsilon)

    # 显示原始图像和对抗样本
    fig, axes = plt.subplots(1, 2, figsize=(10, 5))
    axes[0].imshow(images[0].detach().cpu().permute(1, 2, 0).numpy())  # 使用detach()来移除计算图
    axes[0].set_title("Original Image")
    axes[1].imshow(perturbed_images[0].detach().cpu().permute(1, 2, 0).numpy())  # 使用detach()来移除计算图
    axes[1].set_title(f"Adversarial Image (epsilon={epsilon})")
    plt.show()

# 训练并评估模型
train_losses, train_accuracies = train(model, trainloader, optimizer, loss_fn, epochs=5)
evaluate(model, testloader)

# 绘制训练过程中的损失和准确率曲线
def plot_training_curves(train_losses, train_accuracies):
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.plot(train_losses, label="Training Loss")
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(train_accuracies, label="Training Accuracy")
    plt.xlabel('Epochs')
    plt.ylabel('Accuracy')
    plt.legend()

    plt.show()

plot_training_curves(train_losses, train_accuracies)

# 可视化对抗攻击效果
visualize_attack(model, testloader, epsilon)

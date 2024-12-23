import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import cv2
import os
import matplotlib.pyplot as plt
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms

# 1. 构建U-Net模型
class UNet(nn.Module):
    def __init__(self, in_channels=3, out_channels=1):
        super(UNet, self).__init__()
        
        # 编码器部分
        self.encoder1 = self.conv_block(in_channels, 64)
        self.encoder2 = self.conv_block(64, 128)
        self.encoder3 = self.conv_block(128, 256)
        self.encoder4 = self.conv_block(256, 512)

        # 解码器部分
        self.decoder3 = self.conv_block(512 + 256, 256)
        self.decoder2 = self.conv_block(256 + 128, 128)
        self.decoder1 = self.conv_block(128 + 64, 64)

        # 上采样
        self.upconv3 = self.upconv_block(256, 128)
        self.upconv2 = self.upconv_block(128, 64)
        self.upconv1 = nn.ConvTranspose2d(64, out_channels, kernel_size=2, stride=2)

        # 最后一层输出
        self.final = nn.Conv2d(64, out_channels, kernel_size=1)

    def conv_block(self, in_channels, out_channels):
        return nn.Sequential(
            nn.Conv2d(in_channels, out_channels, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(out_channels, out_channels, kernel_size=3, padding=1),
            nn.ReLU(inplace=True)
        )

    def upconv_block(self, in_channels, out_channels):
        return nn.ConvTranspose2d(in_channels, out_channels, kernel_size=2, stride=2)

    def forward(self, x):
        # 编码器
        enc1 = self.encoder1(x)
        enc2 = self.encoder2(enc1)
        enc3 = self.encoder3(enc2)
        enc4 = self.encoder4(enc3)

        # 解码器
        dec3 = self.upconv3(enc4)
        dec3 = torch.cat([dec3, enc3], dim=1)  # Skip connection
        dec3 = self.decoder3(dec3)

        dec2 = self.upconv2(dec3)
        dec2 = torch.cat([dec2, enc2], dim=1)
        dec2 = self.decoder2(dec2)

        dec1 = self.upconv1(dec2)
        dec1 = torch.cat([dec1, enc1], dim=1)
        dec1 = self.decoder1(dec1)

        out = self.final(dec1)

        return out

# 2. 数据预处理：加载图像数据集
class SegmentationDataset(Dataset):
    def __init__(self, image_paths, label_paths, transform=None):
        self.image_paths = image_paths
        self.label_paths = label_paths
        self.transform = transform

    def __len__(self):
        return len(self.image_paths)

    def __getitem__(self, idx):
        img = cv2.imread(self.image_paths[idx])
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)  # 转换为RGB格式
        img = cv2.resize(img, (256, 256))  # 统一大小

        label = cv2.imread(self.label_paths[idx], cv2.IMREAD_GRAYSCALE)  # 读取标签图
        label = cv2.resize(label, (256, 256))  # 统一大小
        label = np.expand_dims(label, axis=-1)  # 增加维度，成为(256, 256, 1)

        if self.transform:
            img = self.transform(img)

        return img, label

# 转换为Tensor并归一化
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
])

# 3. 加载数据集
image_paths = ['image1.jpg', 'image2.jpg']  # 图像路径列表
label_paths = ['label1.png', 'label2.png']  # 标签路径列表

dataset = SegmentationDataset(image_paths, label_paths, transform=transform)
train_loader = DataLoader(dataset, batch_size=8, shuffle=True)

# 4. 训练模型
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = UNet().to(device)

criterion = nn.BCEWithLogitsLoss()  # 使用BCE损失函数
optimizer = optim.Adam(model.parameters(), lr=1e-4)

def train_model(model, train_loader, criterion, optimizer, num_epochs=10):
    for epoch in range(num_epochs):
        model.train()
        running_loss = 0.0
        for images, labels in train_loader:
            images = images.to(device)
            labels = labels.to(device)

            optimizer.zero_grad()

            outputs = model(images)
            loss = criterion(outputs, labels.float())
            loss.backward()
            optimizer.step()

            running_loss += loss.item()

        print(f"Epoch [{epoch+1}/{num_epochs}], Loss: {running_loss/len(train_loader)}")

# 训练模型
train_model(model, train_loader, criterion, optimizer)

# 5. 使用训练好的模型进行预测
def predict(model, image):
    model.eval()
    with torch.no_grad():
        image = torch.from_numpy(image).unsqueeze(0).float().to(device)
        output = model(image)
        output = torch.sigmoid(output)
        output = output.squeeze().cpu().numpy()
        return output

# 6. 预测与可视化
def visualize_results(image, prediction, output_path):
    # 将预测结果转换为二值图像
    prediction = (prediction > 0.5).astype(np.uint8) * 255

    # 可视化
    plt.figure(figsize=(10, 5))

    # 原始图像
    plt.subplot(1, 2, 1)
    plt.imshow(image)
    plt.title("Original Image")
    plt.axis('off')

    # 预测结果
    plt.subplot(1, 2, 2)
    plt.imshow(prediction, cmap='gray')
    plt.title("Predicted Segmentation")
    plt.axis('off')

    # 保存结果
    plt.savefig(output_path)
    plt.close()

# 加载测试图像
test_image = cv2.imread('test_image.jpg')
test_image = cv2.cvtColor(test_image, cv2.COLOR_BGR2RGB)
test_image = cv2.resize(test_image, (256, 256))  # 统一大小

# 使用训练好的模型进行预测
prediction = predict(model, test_image)

# 可视化预测结果
visualize_results(test_image, prediction, 'segmentation_result.jpg')
print("Segmentation result saved to 'segmentation_result.jpg'")

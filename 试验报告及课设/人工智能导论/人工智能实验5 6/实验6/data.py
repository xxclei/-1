from torchvision import datasets, transforms

transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5,), (0.5,))])

testset = datasets.MNIST(root='/home/xclei/桌面/试验报告/人工智能导论/实验6/data/MNIST/raw', train=False, download=False, transform=transform)

# 打印数据集大小
print(len(testset))

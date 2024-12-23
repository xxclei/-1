import cv2
import numpy as np
from skimage.segmentation import slic
from skimage import segmentation
import os
import matplotlib.pyplot as plt

# 获取目标文件夹路径
input_folder = '/home/xclei/桌面/试验报告/数字图像处理/课程设计图像（视频）素材/感兴趣目标提取'  # 替换为你的图片文件夹路径
output_folder = 'output_folder'  # 替换为输出文件夹路径

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 读取文件夹中的所有图片文件
image_files = [f for f in os.listdir(input_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
image_files = sorted(image_files)[:10]  # 只处理前10张图片

# 处理每张图片
for image_file in image_files:
    # 读取图像
    image = cv2.imread(os.path.join(input_folder, image_file))
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # 使用高斯模糊
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # 使用Canny边缘检测（调整阈值以减少边缘）
    edges = cv2.Canny(blurred, 50, 100)  # 增加Canny阈值来减少边缘数量

    # SLIC超像素分割（减少超像素数量以减少边缘）
    segments = slic(image, n_segments=100, compactness=20, sigma=1)  # 减少n_segments和增加compactness来合并超像素

    # 获取超像素边缘
    slic_edges = np.zeros_like(image)
    slic_edges[segmentation.find_boundaries(segments)] = [255, 255, 255]  # 只保留SLIC超像素边缘

    # N-cut方法（模拟）
    ncut_segments = segmentation.slic(image, n_segments=100, compactness=20)  # 减少n_segments来减少分割的数量
    ncut_edges = np.zeros_like(image)
    ncut_edges[segmentation.find_boundaries(ncut_segments)] = [255, 255, 255]  # 只保留N-cut边缘

    # 可视化每一张图片的前后对比图（四个子图）
    plt.figure(figsize=(15, 15))

    # 处理前图像展示
    plt.subplot(1, 3, 1)
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.title("Original Image")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - SLIC边缘
    plt.subplot(1, 3, 2)
    plt.imshow(cv2.cvtColor(slic_edges, cv2.COLOR_BGR2RGB))
    plt.title("SLIC Edges")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - N-Cut边缘
    plt.subplot(1, 3, 3)
    plt.imshow(cv2.cvtColor(ncut_edges, cv2.COLOR_BGR2RGB))
    plt.title("N-Cut Edges")
    plt.axis('off')  # 关闭坐标轴

    # 保存每张图的效果图
    effect_image_path = os.path.join(output_folder, f'{os.path.splitext(image_file)[0]}_edges.jpg')
    plt.savefig(effect_image_path)
    plt.close()

    print(f"Saved {effect_image_path}")

print("Processing complete!")

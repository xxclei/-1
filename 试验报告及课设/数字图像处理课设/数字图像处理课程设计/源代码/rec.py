import cv2
import numpy as np
from skimage.segmentation import slic
from skimage import segmentation, color
import os
import matplotlib.pyplot as plt

# 获取目标文件夹路径
input_folder = r'project\output'  # 替换为你的图片文件夹路径
output_folder = 'output_folder_strethened'  # 替换为输出文件夹路径

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 读取文件夹中的所有图片文件
image_files = [f for f in os.listdir(input_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
image_files = sorted(image_files)[:11]  # 只处理前10张图片

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
    segments = slic(image, n_segments=350, compactness=20, sigma=1)  # 减少n_segments和增加compactness来合并超像素
    slic_colored = color.label2rgb(segments, image, kind='avg')

    # N-cut方法（模拟）
    ncut_segments = segmentation.slic(image, n_segments=350, compactness=20)  # 减少n_segments来减少分割的数量
    ncut_colored = color.label2rgb(ncut_segments, image, kind='avg')

    # 分水岭算法 (基于标记的分水岭)
    # 应用阈值以获得二值图像
    ret, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
    
    # 形态学操作去除噪声并获得确定的背景
    kernel = np.ones((3, 3), np.uint8)
    sure_bg = cv2.dilate(thresh, kernel, iterations=3)
    
    # 距离变换以获得确定的前景
    dist_transform = cv2.distanceTransform(thresh, cv2.DIST_L2, 5)
    ret, sure_fg = cv2.threshold(dist_transform, 0.7 * dist_transform.max(), 255, 0)
    sure_fg = np.uint8(sure_fg)
    
    # 从确定的背景中减去确定的前景以获得未知区域
    unknown = cv2.subtract(sure_bg, sure_fg)
    
    # 标记标记
    ret, markers = cv2.connectedComponents(sure_fg)
    markers = markers + 1
    markers[unknown == 255] = 0
    
    # 应用分水岭算法
    markers = cv2.watershed(image, markers)
    image[markers == -1] = [255, 0, 0]
    watershed_colored = color.label2rgb(markers, image, kind='avg')

    # 可视化每一张图片的前后对比图（四个子图）
    plt.figure(figsize=(20, 20))

    # 处理前图像展示
    plt.subplot(2, 2, 1)
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.title("Original Image")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - SLIC边缘
    plt.subplot(2, 2, 2)
    plt.imshow(slic_colored)
    plt.title("SLIC Segmentation")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - N-Cut边缘
    plt.subplot(2, 2, 3)
    plt.imshow(ncut_colored)
    plt.title("N-Cut Segmentation")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - Watershed边缘
    plt.subplot(2, 2, 4)
    plt.imshow(watershed_colored)
    plt.title("Watershed Segmentation")
    plt.axis('off')  # 关闭坐标轴

    # 保存每张图的效果图
    effect_image_path = os.path.join(output_folder, f'{os.path.splitext(image_file)[0]}_edges.jpg')
    plt.savefig(effect_image_path)
    plt.close()

    print(f"Saved {effect_image_path}")

print("Processing complete!")

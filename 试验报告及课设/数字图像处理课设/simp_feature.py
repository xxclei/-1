import cv2
import numpy as np
from skimage.segmentation import slic
from skimage import color
from sklearn.cluster import KMeans
import os
import matplotlib.pyplot as plt
from skimage.feature import graycomatrix, graycoprops
from skimage import morphology

# 获取目标文件夹路径
input_folder = 'project\\1'  # 替换为你的图片文件夹路径
output_folder = 'output_folder3_mul'  # 替换为输出文件夹路径

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 读取文件夹中的所有图片文件
image_files = [f for f in os.listdir(input_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
image_files = sorted(image_files)[:11]  # 只处理前10张图片

def extract_features(image, segments):
    features = []
    for segment_val in np.unique(segments):
        # 获取每个超像素区域的像素
        mask = segments == segment_val
        region_pixels = image[mask]
        
        # 计算特征：颜色均值（R, G, B）
        mean_color = np.mean(region_pixels, axis=0)
        
        # 计算纹理特征：灰度共生矩阵
        glcm = graycomatrix(region_pixels.astype(np.uint8), distances=[1], angles=[0], levels=256, symmetric=True, normed=True)
        contrast = graycoprops(glcm, 'contrast')[0, 0]
        homogeneity = graycoprops(glcm, 'homogeneity')[0, 0]
        
        # 计算边缘信息：Sobel算子
        sobel_x = cv2.Sobel(region_pixels, cv2.CV_64F, 1, 0, ksize=3)
        sobel_y = cv2.Sobel(region_pixels, cv2.CV_64F, 0, 1, ksize=3)
        edge_magnitude = np.sqrt(sobel_x**2 + sobel_y**2)
        
        # 计算形状特征：区域面积和周长
        area = np.sum(mask)
        contours, _ = cv2.findContours(mask.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        perimeter = sum(cv2.arcLength(contour, True) for contour in contours)
        
        # 调整特征重要性
        # 调整特征重要性
        # 颜色均值权重

        weighted_mean_color = mean_color * 1.5
        # 纹理特征权重：对比度
        weighted_contrast = contrast * 1.5
        # 纹理特征权重：同质性
        weighted_homogeneity = homogeneity * 2
        # 边缘信息权重：边缘幅度
        weighted_edge_magnitude = np.mean(edge_magnitude) * 1.0
        # 形状特征权重：区域面积
        weighted_area = area * 0.2
        # 形状特征权重：周长
        weighted_perimeter = perimeter * 0.8


        # 将所有特征组合在一起
        features.append(np.concatenate((weighted_mean_color, [weighted_contrast, weighted_homogeneity], [weighted_edge_magnitude, weighted_area, weighted_perimeter])))
    
    return np.array(features)

# 处理每张图片
for image_file in image_files:
    # 读取图像
    image = cv2.imread(os.path.join(input_folder, image_file))
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # 转为RGB格式
    
    # 使用SLIC进行超像素分割
    segments = slic(image_rgb, n_segments=200, compactness=30, sigma=1)
    
    # 提取每个超像素的特征
    features = extract_features(image_rgb, segments)
    
    # 使用KMeans进行分类（模拟语义分割）
    kmeans = KMeans(n_clusters=2)  # 假设我们有3个类（例如：背景、前景、目标）
    kmeans.fit(features)
    
    # 获取每个超像素的标签
    labels = kmeans.labels_
    
    # 为每个超像素分配颜色
    segmented_image = np.zeros_like(image_rgb)
    for i, label in enumerate(np.unique(segments)):
        mask = segments == label
        segmented_image[mask] = np.array([255 * (labels[i] == 0), 255 * (labels[i] == 1), 255 * (labels[i] == 2)], dtype=np.uint8)
    
    # 可视化每一张图片的前后对比图（四个子图）
    plt.figure(figsize=(15, 15))

    # 处理前图像展示
    plt.subplot(2, 2, 1)
    plt.imshow(image_rgb)
    plt.title("Original Image")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - 超像素边缘
    plt.subplot(2, 2, 2)
    plt.imshow(segmented_image)
    plt.title("Segmented Image")
    plt.axis('off')  # 关闭坐标轴

    # 保存每张图的效果图
    effect_image_path = os.path.join(output_folder, f'{os.path.splitext(image_file)[0]}_segmentation.jpg')
    plt.savefig(effect_image_path)
    plt.close()

    print(f"Saved {effect_image_path}")

print("Processing complete!")

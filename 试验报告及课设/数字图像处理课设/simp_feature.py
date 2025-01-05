import cv2
import numpy as np
from skimage.segmentation import slic, mark_boundaries
from skimage import color
from sklearn.cluster import KMeans
import os
import matplotlib.pyplot as plt
from skimage.feature import graycomatrix, graycoprops
from skimage import morphology
from skimage.measure import label, regionprops

# 获取目标文件夹路径
input_folder = 'project\\output'  # 替换为你的图片文件夹路径
output_folder = 'output_cluster'  # 替换为输出文件夹路径

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 读取文件夹中的所有图片文件
image_files = [f for f in os.listdir(input_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
image_files = sorted(image_files)[:10]  # 只处理前10张图片

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
        
        # 调整特征重要性
        # 颜色均值权重
        weighted_mean_color = mean_color * 10
        # 纹理特征权重：对比度
        weighted_contrast = contrast * 0
        # 纹理特征权重：同质性
        weighted_homogeneity = homogeneity * 6

        # 将所有特征组合在一起
        all_features = np.concatenate((weighted_mean_color, [weighted_contrast, weighted_homogeneity]))
        features.append(all_features)
    
    return np.array(features)

def merge_superpixels(segments, features, threshold=0.5):
    merged_segments = segments.copy()
    unique_segments = np.unique(segments)
    for i in range(len(unique_segments)):
        for j in range(i + 1, len(unique_segments)):
            if np.linalg.norm(features[i] - features[j]) < threshold:
                merged_segments[segments == unique_segments[j]] = unique_segments[i]
    
    # Ensure connectivity using morphological closing
    kernel = np.ones((5, 5), np.uint8)
    merged_segments = morphology.closing(merged_segments, kernel)
    
    return merged_segments

# 处理每张图片
for image_file in image_files:
    # 读取图像
    image = cv2.imread(os.path.join(input_folder, image_file))
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # 转为RGB格式
    
    # 使用SLIC进行超像素分割
    segments = slic(image_rgb, n_segments=350, compactness=20, sigma=1)
    
    # 提取每个超像素的特征
    features = extract_features(image_rgb, segments)
    
    # 合并超像素
    merged_segments = merge_superpixels(segments, features)
    
    # 提取感兴趣目标
    roi_mask = merged_segments == np.argmax(np.bincount(merged_segments.flat))
    
    # 使用形态学闭操作确保前景完全连通
    kernel = np.ones((5, 5), np.uint8)
    roi_mask = cv2.morphologyEx(roi_mask.astype(np.uint8), cv2.MORPH_CLOSE, kernel)
    
    # 连接组件分析以找到最大连通区域
    labeled_mask = label(roi_mask)
    regions = regionprops(labeled_mask)
    largest_region = max(regions, key=lambda r: r.area)
    largest_region_mask = labeled_mask == largest_region.label
    
    roi_image = image_rgb * largest_region_mask[:, :, np.newaxis]
    
    # 可视化每一张图片的前后对比图（三个子图）
    plt.figure(figsize=(15, 5))

    # 处理前图像展示
    plt.subplot(1, 3, 1)
    plt.imshow(image_rgb)
    plt.title("Original Image")
    plt.axis('off')  # 关闭坐标轴

    # 超像素分割结果展示
    plt.subplot(1, 3, 2)
    plt.imshow(mark_boundaries(image_rgb, segments, color=(0, 0, 0)))
    plt.title("Superpixel Segmentation")
    plt.axis('off')  # 关闭坐标轴

    # 处理后图像展示 - 感兴趣目标
    plt.subplot(1, 3, 3)
    plt.imshow(roi_image)
    plt.title("Region of Interest")
    plt.axis('off')  # 关闭坐标轴

    # 保存每张图的效果图
    effect_image_path = os.path.join(output_folder, f'{os.path.splitext(image_file)[0]}_roi.jpg')
    plt.savefig(effect_image_path)
    plt.close()

    print(f"Saved {effect_image_path}")

print("Processing complete!")

import os
from PIL import Image, ImageEnhance
import cv2
import numpy as np
import matplotlib.pyplot as plt

output_folder = 'output_strengthened_images'
input_folder = r'project\1'
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 读取文件夹中的所有图片文件
image_files = [f for f in os.listdir(input_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
image_files = sorted(image_files)[:11]  # 只处理前10张图片

# 处理每张图片
for image_file in image_files:
    # 打开图片
    image_path = os.path.join(input_folder, image_file)
    image = Image.open(image_path)
    
    # 对比度增强
    enhancer = ImageEnhance.Contrast(image)
    image_contrast = enhancer.enhance(1.3)  # 增强对比度，参数3.0表示对比度增强两倍

    # 锐化增强
    enhancer = ImageEnhance.Sharpness(image_contrast)
    image_sharp = enhancer.enhance(2.5)  # 增强锐化，参数1.5表示锐化增强一倍

    # 转换为OpenCV格式
    image_cv = cv2.cvtColor(np.array(image_sharp), cv2.COLOR_RGB2BGR)

    # 双边滤波
    bilateral_filtered_image = cv2.bilateralFilter(image_cv, d=9, sigmaColor=75, sigmaSpace=75)

    # 拉普拉斯算子
    laplacian_image = cv2.Laplacian(bilateral_filtered_image, cv2.CV_64F)
    laplacian_image = cv2.convertScaleAbs(laplacian_image)

    # 将拉普拉斯图像叠加到原图上
    strengthened_image = cv2.addWeighted(image_cv, 1, laplacian_image, 0.5, 0)

    # 转换回PIL图像并转换为RGB格式
    strengthened_image_pil = Image.fromarray(cv2.cvtColor(strengthened_image, cv2.COLOR_BGR2RGB))

    # 保存处理后的图像
    output_path = os.path.join(output_folder, f'strengthened_image_{image_file}')
    strengthened_image_pil.save(output_path)

    # 绘制对比图
    enhancers = {
        'Original': image,
        'Strengthened': strengthened_image_pil
    }

    fig, axes = plt.subplots(1, len(enhancers), figsize=(10, 5))
    for ax, (title, enhanced_image) in zip(axes, enhancers.items()):
        ax.imshow(enhanced_image)
        ax.set_title(title)
        ax.axis('off')

    # 保存对比图
    comparison_output_path = os.path.join(output_folder, f'comparison_{image_file}')
    plt.savefig(comparison_output_path)
    plt.close()

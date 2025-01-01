import cv2
import numpy as np
import os
import matplotlib.pyplot as plt
# 定义图像路径
image_path='simple cut result\images'
output_path='simple cut result\output'

image_list=[]
# 遍历图像路径中的所有文件
for img in os.listdir(image_path):
    # 读取图像文件
    image=(cv2.imread(os.path.join(image_path,img)))
    # 将图像从BGR颜色空间转换为RGB颜色空间
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # 调整图像大小
    
    # 将图像添加到列表中
    image_list.append(image_rgb)
     

for image in image_list:
    image_gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)  # 转为灰度模式
    image_resized = cv2.resize(image_gray, (400, 300))
    plt.imshow(image_gray, cmap='gray')
    # 应用阈值分割
    # 寻找阈值
    # 绘制直方图
    os.makedirs(output_path, exist_ok=True)
    plt.figure()
    plt.hist(image_resized.ravel(), bins=256, range=[0, 256])
    plt.title("Histogram")
    plt.xlabel("Pixel value")
    plt.ylabel("Frequency")
    index = next(i for i, img in enumerate(image_list) if np.array_equal(img, image))
    plt.savefig(os.path.join(output_path, f"histogram_{index}.png"))
    plt.close()

    # 对第一三四张图片进行三角阈值分割 已知直方图为单峰
    if index in [1, 3, 4]:
        hist = cv2.calcHist([image_resized], [0], None, [256], [0, 256])
        hist = hist.ravel()
        # 使用三角阈值法
        left, right = 0, 255
        while hist[left] == 0:
            left += 1
        while hist[right] == 0:
            right -= 1
        if left >= right:
            best_thresh = 127  # 默认阈值
        else:
            max_dist = 0
            best_thresh = left
            for i in range(left, right + 1):
                dist = np.abs((right - left) * hist[i] - (i - left) * (hist[right] - hist[left]))
                if dist > max_dist:
                    max_dist = dist
                    best_thresh = i

        print(best_thresh)
        _, thresh_image = cv2.threshold(image_gray, best_thresh, 255, cv2.THRESH_BINARY)
        plt.imshow(thresh_image, cmap='gray')
        plt.title(f"Thresholded Image (Threshold: {best_thresh})")
        plt.show()
    # 对所有图片使用OSTU自动阈值法
    _, otsu_thresh_image = cv2.threshold(image_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    plt.imshow(otsu_thresh_image, cmap='gray')
    plt.title(f"OSTU Thresholded Image")
    plt.show()

    # 保存分割后的图片
    otsu_output_path = os.path.join(output_path, 'OSTU_CUT')
    os.makedirs(otsu_output_path, exist_ok=True)
    cv2.imwrite(os.path.join(otsu_output_path, f"otsu_thresh_image_{index}.png"), otsu_thresh_image)
    # plt.imshow(thresh_image, cmap='gray')
    # plt.title("Thresholded Image")
    # plt.show()
    
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <time.h>
#include <random>
#include <Windows.h>  // Windows API
#define MAX_SIZE 150000

typedef struct SeqList {
	int* r; // r[0]闲置
	int length; // 顺序表总长度
} SeqList;

// 建立并初始化线性表
void InitSeqList(SeqList* L) {
//    assert(L); // 检验指针有效性
	L->r = (int*)malloc(MAX_SIZE * sizeof(int)); // 动态分配空间
	if (!L->r) {
		printf("开辟空间失败！");
		return;
	}
	L->length = 0;
}

// 产生随机数
void CreateShow(SeqList* L, int n) {
	std::random_device rd;  // 获得硬件随机数生成器（如果支持）
	std::mt19937 gen(rd()); // 使用梅森旋转算法
	std::uniform_int_distribution<> dis(0, 9999999);  // 生成0到9999999之间的随机数
	
	for (int i = 0; i < n; i++) {
		L->r[i] = dis(gen);  // 生成随机数
	}
	L->length = n;
}

// 保存数据到文件
void SaveSeqList(SeqList* L, FILE* p) {
	for (int i = 1; i < L->length; i++)
		fprintf(p, "%d  ", L->r[i]);
	fprintf(p, "\n\n");
}

// 交换两个数
void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// 深拷贝顺序表
void DeepCopySeqList(SeqList* dest, SeqList* src) {
//    assert(dest != NULL && src != NULL); // 检查指针有效性
	
	// 为目标顺序表分配空间
	dest->r = (int*)malloc(MAX_SIZE * sizeof(int));
	if (!dest->r) {
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	
	// 深拷贝数据
	for (int i = 0; i <= src->length; i++) {
		dest->r[i] = src->r[i];
	}
	
	// 拷贝长度
	dest->length = src->length;
}

// 插入排序 
void InsertSort(SeqList* L) {
	int i, j;
//    assert(L); 
	if (L->length == 1)
	{
		printf("需要排序的数据为空！");
		return;
	}
	for (i = 1; i <= L->length - 1; ++i) {
		if (L->r[i] < L->r[i - 1]) { // 当“<”时，才需将r[i]插入有序表
			L->r[0] = L->r[i];
			// 将待插入记录复制为哨兵
			j = i - 1;
			while (L->r[0] < L->r[j]) {
				L->r[j + 1] = L->r[j];       // 记录后移 
				j--;
			}
			L->r[j + 1] = L->r[0];        // 插入 
		}
	}
}

// 冒泡排序  
void BubbleSort(SeqList* L) {
	for (int i = L->length - 2; i > 0; i--) { // 外循环
		for (int j = 1; j <= i; j++) { // 内循环
			if (L->r[j] > L->r[j + 1]) {
				swap(&L->r[j], &L->r[j + 1]);
			}
		}
	}
}

int MedianOfThree(SeqList* L, int low, int high) {
	int mid = (low + high) / 2;
	if (L->r[mid] < L->r[low]) {
		swap(&L->r[mid], &L->r[low]);
	}
	if (L->r[high] < L->r[low]) {
		swap(&L->r[high], &L->r[low]);
	}
	if (L->r[mid] > L->r[high]) {
		swap(&L->r[mid], &L->r[high]);
	}
	return mid;
}
// 快速排序
void QuickSort(SeqList* L, int low, int high) {
	if (low < high) {
		int pivotIndex = MedianOfThree(L, low, high);
		swap(&L->r[pivotIndex], &L->r[low]);
		int pivot = L->r[low];
		int i = low + 1, j = high;
		
		while (i <= j) {
			while (i <= j && L->r[i] <= pivot) i++;
			while (i <= j && L->r[j] >= pivot) j--;
			if (i < j) swap(&L->r[i], &L->r[j]);
		}
		swap(&L->r[low], &L->r[j]);
		QuickSort(L, low, j - 1);
		QuickSort(L, j + 1, high);
	}
}



// 选择排序  
void SelectSort(SeqList* L) {
//    assert(L);
	int i;
	int k;
	for (i = 1; i < L->length - 1; ++i) { // 选择第i个小的记录，并交换到位
		int j = i; // j用于记录最小元素的位置
		for (k = i + 1; k <= L->length - 1; k++) { // 在数组中选择key最小的元素
			if (L->r[k] < L->r[j])
				j = k;
		}
		if (i != j) { // 第i个小的记录L->r[j]与第i个记录交换
			swap(&L->r[i], &L->r[j]);
		}
	}
}

// 堆排序
void heapify(SeqList* L, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && L->r[left] > L->r[largest]) {
		largest = left;
	}
	
	if (right < n && L->r[right] > L->r[largest]) {
		largest = right;
	}
	
	if (largest != i) {
		swap(&L->r[i], &L->r[largest]);
		heapify(L, n, largest); // 递归调整子树
	}
}

void HeapSort(SeqList* L) {
	int n = L->length;
	
	// 建堆
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(L, n, i);
	}
	
	// 排序
	for (int i = n - 1; i > 0; i--) {
		swap(&L->r[0], &L->r[i]); // 将最大值移到数组末尾
		heapify(L, i, 0); // 调整剩余部分为堆
	}
}



// 归并排序函数的具体实现
void MergeArray(SeqList* L, int low, int mid, int high) {
//    assert(L);
	int i, j, k, len1, len2;
	int* front, * back;
	len1 = mid - low + 1;
	len2 = high - mid;
	front = (int*)malloc(len1 * sizeof(int));
	back = (int*)malloc(len2 * sizeof(int));
	if (!front || !back) {
		printf("内存分配失败！");
		if (front) free(front);
		if (back) free(back);
		return;
	}
	for (i = 0; i < len1; i++)
		front[i] = L->r[low + i];
	for (j = 0; j < len2; j++)
		back[j] = L->r[mid + 1 + j];
	i = 0; j = 0; k = low;
	while (i < len1 && j < len2) {
		if (front[i] <= back[j]) {
			L->r[k++] = front[i++];
		}
		else {
			L->r[k++] = back[j++];
		}
	}
	while (i < len1) {
		L->r[k++] = front[i++];
	}
	while (j < len2) {
		L->r[k++] = back[j++];
	}
	free(front);
	free(back);
}

// 归并排序函数的具体实现
void MergeSort(SeqList* L, int low, int high) {
//    assert(L);
	if (low < high) {
		int middle = (low + high) / 2;
		MergeSort(L, low, middle);
		MergeSort(L, middle + 1, high);
		MergeArray(L, low, middle, high);
	}
}

// 希尔排序
void ShellSort(SeqList* L) {
//    assert(L);
	int d = L->length / 2; // 初始增量
	while (d >= 1) {
		for (int i = d; i < L->length; i++) { // 注意索引从0开始
			int temp = L->r[i];
			int j = i - d;
			while (j >= 0 && L->r[j] > temp) {
				L->r[j + d] = L->r[j];
				j -= d;
			}
			L->r[j + d] = temp;
		}
		d /= 2;
	}
}
void FreeSeqList(SeqList* L) {
	if (L->r) {
		free(L->r);
		L->r = NULL;
	}
	L->length = 0;
}


int main() {
	int n;
	printf("请输入要排序的元素个数(按0退出)：");
	scanf("%d", &n);
	while (n > 0) {
		FILE* p = fopen("file.txt", "a");
		FILE* p1 = fopen("file1.txt", "a");
		FILE* p2 = fopen("file2.txt", "a");
		FILE* p3 = fopen("file3.txt", "a");
		FILE* p4 = fopen("file4.txt", "a");
		FILE* p5 = fopen("file5.txt", "a");
		FILE* p6 = fopen("file6.txt", "a");
		FILE* p7 = fopen("file7.txt", "a");
		SeqList L, L1, L2, L3, L4, L5, L6, L7;
		srand((unsigned int)time(NULL));
		InitSeqList(&L); // 初始化
		InitSeqList(&L1);
		InitSeqList(&L2);
		InitSeqList(&L3);
		InitSeqList(&L4);
		InitSeqList(&L5);
		InitSeqList(&L6);
		InitSeqList(&L7);
		CreateShow(&L, n);
		SaveSeqList(&L, p);
		DeepCopySeqList(&L1, &L);
		DeepCopySeqList(&L2, &L);
		DeepCopySeqList(&L3, &L);
		DeepCopySeqList(&L4, &L);
		DeepCopySeqList(&L5, &L);
		DeepCopySeqList(&L6, &L);
		DeepCopySeqList(&L7, &L);
		clock_t start, end; // clock_t用于计时开始时间和结束时间
		start = clock();
		InsertSort(&L1);
		end = clock();
		SaveSeqList(&L1, p1);
		printf("插入排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		BubbleSort(&L2);
		end = clock();
		SaveSeqList(&L2, p2);
		printf("冒泡排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		QuickSort(&L3, 1, L3.length - 1);
		end = clock();
		SaveSeqList(&L3, p3);
		printf("快速排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		SelectSort(&L4);
		end = clock();
		SaveSeqList(&L4, p4);
		printf("选择排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		HeapSort(&L5);
		end = clock();
		SaveSeqList(&L5, p5);
		printf("堆排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		MergeSort(&L6, 0, L6.length - 1);
		end = clock();
		SaveSeqList(&L6, p6);
		printf("归并排序时间是:%f毫秒\n", (float)(end - start));
		
		start = clock();
		ShellSort(&L7);
		end = clock();
		SaveSeqList(&L7, p7);
		printf("希尔排序时间是:%f毫秒\n", (float)(end - start));
		
		fclose(p);
		fclose(p1);
		fclose(p2);
		fclose(p3);
		fclose(p4);
		fclose(p5);
		fclose(p6);
		fclose(p7);
		
		printf("请输入要排序的元素个数(按0退出)：");
		scanf("%d", &n);
		FreeSeqList(&L);
		FreeSeqList(&L1);
		FreeSeqList(&L2);
		FreeSeqList(&L3);
		FreeSeqList(&L4);
		FreeSeqList(&L5);
		FreeSeqList(&L6);
		FreeSeqList(&L7);
		
	}
	system("pause");
	return 0;
}


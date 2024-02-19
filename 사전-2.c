//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//int findElement(int* arr, int, int, int);
//
//
//int main() {
//	int num, key;
//	int* arr;
//	int temp;
//	scanf("%d", &num);
//
//	arr = (int*)malloc(num * sizeof(int));
//
//	scanf("%d", &key);
//
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	temp = findElement(arr, 0, num, key);
//
//	printf("%d", temp);
//
//	free(arr);
//}
//int findElement(int* arr, int first, int last, int key) {
//	int l = 0;
//	int r = last - 1;
//	int temp = -1;
//	int mid;
//	while (l <= r) {
//		mid = (l + r) / 2;
//		if (key == arr[mid]) {
//			return mid;
//		}
//		else if (key < arr[mid]) {
//			temp = mid;
//			r = mid - 1;
//		}
//		else if (key > arr[mid]) {
//			temp = mid+1;
//			l = mid + 1;
//
//		}
//
//	}
//	return temp;
//}
//
//

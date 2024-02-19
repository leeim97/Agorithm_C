//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//
//int main() {
//	int* arr;
//	int num;
//
//	scanf("%d", &num);
//
//	arr = (int*)malloc(sizeof(int) * num);
//
//
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	for (int i = 1; i < num; i++) {
//		int key = arr[i];
//		int j = i - 1;
//		while (j >= 0 && key < arr[j]) {
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = key;
//
//	}
//	for (int i = 0; i < num; i++) {
//		printf("%d", arr[i]);
//	}
//
//
//}
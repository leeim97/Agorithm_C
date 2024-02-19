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
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	for (int i = num - 1; i >= 1; i--) {
//		int key = arr[i];
//		int loc = i;
//		for (int j = i - 1; j >= 0; j--) {
//			if (key < arr[j]) {
//				key = arr[j];
//				loc = j;
//			}
//		}
//		arr[loc] = arr[i];
//		arr[i] = key;
//
//	}
//
//
//	for (int i = 0; i < num; i++) {
//		printf(" %d", arr[i]);
//	}
//
//
//}
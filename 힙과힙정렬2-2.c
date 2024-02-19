//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//int H[MAX_SIZE] = { 0 };
//int index = 0;
//
//void upHeap(int);
//void downHeap(int);
//
//void insertItem(int key) {
//	index += 1;
//	H[index] = key;
//	upHeap(index);
//	//printf("0\n");
//	return;
//}
//
//int removeMax() {
//	int temp = H[1];
//	H[1] = H[index];
//	H[index] = 0;
//	index -= 1;
//	downHeap(1);
//	return temp;
//
//}
//void swap(int* a, int* b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void upHeap(int index) {
//	if (index == 1 || H[index / 2] > H[index]) {
//		return;
//	}
//	if (H[index] > H[index / 2]) {
//		swap(&H[index], &H[index / 2]);
//
//	}
//	upHeap(index / 2);
//}
//
//void downHeap(int root) {
//	int larger;
//
//	if (root * 2 > index) {
//		return;
//	}
//
//	larger = root * 2;
//
//	if (root * 2 + 1 <= index) {
//		if (H[larger] < H[root * 2 + 1])
//			larger = root * 2 + 1;
//	}
//
//	if (H[root] > H[larger])
//		return;
//
//	swap(&H[root], &H[larger]);
//
//
//
//
//	downHeap(larger);
//
//
//}
//void printHeap() {
//
//	for (int i = 1; i <= index; i++) {
//		printf(" %d", H[i]);
//	}
//	//printf("\n");
//}
//
//void inPlaceHeapSort() {
//
//	for (int i = 1; i <= index - 1; i++) {
//		for (int j = i + 1; j <= index; j++) {
//			if (H[i] > H[j]) {
//				swap(&H[i], &H[j]);
//			}
//		}
//
//	}
//}
//
//
///*
// 내가 푼 선택정렬
//void inPlaceHeapSort() {
//	int temp;
//	int ind;
//	for (int i = 1; i <= index-1; i++) {
//		temp = H[i];
//		ind = i;
//		for (int j = i+1; j <= index; j++) {
//			if (temp > H[j ]) {
//				temp = H[j ];
//				ind = j;
//			}
//		}
//		swap(&H[i], &H[ind]);
//	}
//}
//*/
//
//int main() {
//
//	int num, temp;
//	scanf("%d", &num);
//
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &temp);
//		insertItem(temp);
//
//	}
//	inPlaceHeapSort();
//	printHeap();
//
//
//}
//

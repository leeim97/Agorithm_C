//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//int H[MAX_SIZE]={0};
//int index=0;
//
//void upHeap(int);
//void downHeap(int);
//
//void insertItem(int key) {
//	index += 1;
//	H[index] = key;
//	upHeap(index);
//	printf("0\n");
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
//void swap(int* a ,int* b) {
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
//	upHeap(index/2);
//}
//
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
//		printf("%d ", H[i]);
//	}
//	printf("\n");
//}
//
//
//
//int main() {
//	char val='`';
//	int temp;
//	
//	while (1) {
//		scanf("%c", &val);
//
//		if (val == 'q')
//			break;
//
//		if (val == 'i') {
//			scanf("%d", &temp);
//			insertItem(temp);
//		}
//		else if (val == 'd') {
//			temp = removeMax();
//			printf("%d\n", temp);
//		}
//		else if (val == 'p') {
//			printHeap();
//		}
//		
//	}
//
//
//
//
//}
//

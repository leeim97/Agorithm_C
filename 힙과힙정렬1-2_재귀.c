//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//int H[MAX_SIZE] = { 0 };
//int index=0;
//
//void swap(int* a ,int* b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
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
//	downHeap(larger);
//
//
//}
//void rBuildHeap(int root) {
//	if (root <=index){
//		rBuildHeap(root * 2);
//		rBuildHeap(root * 2 + 1);
//		downHeap(root);
//	}
//	else
//		return;
//
//}
//
//void printHeap() {
//
//	for (int i = 1; i <= index; i++) {
//		printf("%d ", H[i]);
//	}
//	printf("\n");
//}
//
//
//int main() {
//	int num;
//
//	scanf("%d", &num);
//	getchar();
//
//	for (int i = 1; i <= num; i++) {
//		scanf("%d", &H[i]);
//		index++;
//	}
//
//	rBuildHeap(1);
//	printHeap();
//}
//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#include<math.h>
//#include <time.h>
//
//int findPivot(int, int);
//int inPlacePartition(int*, int, int, int);
//void inPlaceQuickSort(int*, int l, int r);
//void swap(int*, int*);
//
//int main() {
//	int num;
//	int* arr;
//
//	scanf("%d", &num);
//	arr = (int*)malloc(sizeof(int) * num);
//
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	inPlaceQuickSort(arr, 0, num - 1);
//
//	for (int i = 0; i < num; i++) {
//		printf(" %d", arr[i]);
//	}
//}
//void swap(int* a, int* b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int findPivot(int l, int r) {
//	if (r - l <= 1)
//		return l;
//
//	int rv;
//	srand(time(NULL));
//	rv = (rand() % (r - l + 1) + l);
//	return rv;
//}
//
//void inPlaceQuickSort(int* arr, int l, int r) {
//	int k;
//	int a;
//	int* p = arr;
//
//	if (l >= r)
//		return;
//
//	k = findPivot(l, r);
//
//	a = inPlacePartition(p, l, r, k);
//	inPlaceQuickSort(p, l, a - 1);
//	inPlaceQuickSort(p, a + 1, r);
//
//}
//
//int inPlacePartition(int* arr, int l, int r, int k) {
//	int i, j, temp;
//	int L = l, R = r;
//	temp = arr[k];
//	arr[k] = arr[r];
//	arr[r] = temp;
//
//	i = l;
//	j = r;
//	 
//	for (int i = l; i <= r; i++) {
//
//		if (arr[i] < temp) {
//			swap(&arr[i], &arr[L]);
//			L++;
//		}
//	}
//	
//	L = l;
//	for (int i = l; i <= r; i++) {
//
//		if (arr[i] < temp) {
//			swap(&arr[i], &arr[L]);
//			L++;
//		}
//	}
//
//	swap(&arr[L], &arr[r]);
//
//	return L;
//
//
//
//
//
//}
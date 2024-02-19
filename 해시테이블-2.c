//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//int hash(int M, int key) { // M은 배열 사이즈
//	return key % M;
//}
//
//int linear(int index, int i,int M) {
//	return (index + i) % M;
//}
//
//void insertKey(int* table, int M, int key) {
//	int hashValue = hash(M, key); //해시함수 압축맵 위치 
//	int b;
//	
//	int index = hashValue; //해쉬함수에서 나온 값이 해시값이라고 불리는걸 암기하기위해 불필요하게 써봤다
//	int i = 0;
//	while (i < M) {
//		b = linear(index, i, M);
//		if (table[b] == 0) {
//			table[b] = key;
//			return printf("%d\n",b);
//		}
//		else if (table[b] != 0) {
//			printf("C");
//			i++;
//		}
//		else
//			i++;
//	}
//	//삽입하다가 꽉 차는 거 확인overflowException()
//
//	return;
//}
//
//void searchKey(int* table, int M, int key) {
//	int hashValue = hash(M, key); //해시함수 압축맵 위치 
//	int b;
//
//	int index = hashValue;
//	int i = 0;
//
//	while (i < M) {
//		b = linear(index, i, M);
//		if (table[b] == 0)
//			return printf("%d\n", -1);
//		else if (table[b] == key) {
//			return printf("%d %d\n",b, table[b]);
//		}
//		else
//			i = i + 1;
//	}
//
//	return printf("%d\n", -1);
//
//}
//
//void init(int* table,int M) {
//	for (int i = 0; i < M; i++) {
//		table[i] = 0;
//	}
//}
//
//
//
//int main() {
//	int M;
//	int key;
//	scanf("%d", &M);
//
//	int* table;
//	table = (int*)malloc(sizeof(int) * M);
//	init(table,M);
//
//	int n;
//	scanf("%d", &n);
//
//	char x = ' ';
//
//	while (x != 'e') {
//		scanf("%c", &x);
//		if (x == 'i') {
//			scanf("%d", &key);
//			insertKey(table, M, key);
//		}
//		else if (x == 's') {
//			scanf("%d", &key);
//			searchKey(table, M, key);
//		}
//
//
//	}
//
//
//}
//

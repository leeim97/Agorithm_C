//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//int hash(int M, int key) { // M�� �迭 ������
//	return key % M;
//}
//
//int doubleHashing(int key,int q) {
//	return q - (key % q);
//}
//
//void insertKey(int* table, int M, int key,int q) {
//	int hashValue = hash(M, key); //�ؽ��Լ� ����� ��ġ 
//	int b;
//	int hprime= doubleHashing(key, q);
//	int index = hashValue; //�ؽ��Լ����� ���� ���� �ؽð��̶�� �Ҹ��°� �ϱ��ϱ����� ���ʿ��ϰ� ��ô�
//	int i = 0;
//	while (i < M) {
//		b = (index + i * hprime)%M;
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
//	//�����ϴٰ� �� ���� �� Ȯ��overflowException()
//
//	return;
//}
//
//void searchKey(int* table, int M, int key,int q) {
//	int hashValue = hash(M, key); //�ؽ��Լ� ����� ��ġ 
//	int b;
//
//	int index = hashValue;
//	int i = 0;
//	int hprime= doubleHashing(key, q);
//
//	while (i < M) {
//		b=(index + i * hprime) % M;
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
//void print(int* table, int M) {
//	for (int i = 0; i < M; i++) {
//		printf(" %d", table[i]);
//	}
//	printf("\n");
//}
//	
//int main() {
//	int M;
//	int key;
//	scanf("%d", &M);
//
//	int* table;
//	table = (int*)malloc(sizeof(int) * M);
//	init(table, M);
//
//	int n;
//	scanf("%d", &n);
//	int q;//�����ؽ̿� ���� M���� �ణ ���� �Ҽ�
//	scanf("%d", &q);
//
//	char x = ' ';
//
//
//	while (1) {
//		scanf("%c", &x);
//		if (x == 'i') {
//			scanf("%d", &key);
//			insertKey(table, M, key,q);
//		}
//		else if (x == 's') {
//			scanf("%d", &key);
//			searchKey(table, M, key,q);
//		}
//		else if (x == 'p') {
//			print(table, M);
//
//		}
//		else if (x == 'e') {
//			print(table, M);
//			return;
//		}
//
//	}
//}
//

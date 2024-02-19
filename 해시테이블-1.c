//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//typedef struct node {
//	int data;
//	struct node* next;
//}node;
//
//node* getNode(int key) {
//	node* q = (node*)malloc(sizeof(node));
//	q->next = NULL;
//	q->data = key;
//
//	return q;
//}
//
//int hash(int key, int M) { // M�� �迭 ������
//	return key % M;
//}
//
//void insertKey(node* table, int M, int key) {
//	int index = hash(key, M); //������ v
//	node* p = getNode(key);
//
//	if (table[index].next == NULL) {
//		table[index].next = p;
//	}
//	else if (table[index].next != NULL) {
//		node* q = table[index].next;
//		table[index].next = p;
//		p->next = q;
//	}
//}
//
//void searchKey(node* table, int M, int key) {
//	int index = hash(key, M); //������ v
//	node* p = &table[index];
//
//	int rank = 0;
//
//	while (p->next != NULL) {
//		p = p->next;
//		rank++;
//		
//		if (p->data == key)
//			return printf("%d\n", rank);
//		
//	}
//	
//	return printf("%d\n", 0);
//
//}
//
//void deleteKey(node* table, int M, int key) {
//	int index = hash(key, M);
//	node* p = &table[index]; //��ȸ�� ���
//	node* q=p;					//key�� �����ϰ� �ִ� ��� ���ſ�
//
//	int rank = 0;
//	while (p->next != NULL) {
//		p = p->next;
//		rank++;
//
//		if (p->data == key) {
//			q->next = p->next;
//			free(p);
//			return printf("%d\n", rank);
//		}
//		q = p; //q�� �ѹ��ھ� �ʰ� ������Ʈ��
//			   //�ֳĸ� p���� ���� ������带 �̾�����ϹǷ�
//	}
//	return printf("%d\n", 0);
//}
//
//void printTable(node* table, int M) {
//	node* q;
//
//	for (int i = 0; i < M; i++) {
//		q = &table[i];
//
//		while (q->next != NULL) {
//			q = q->next;
//			printf(" %d", q->data);
//		}
//		
//	}
//	printf("\n");
//}
//
//int main() {
//	int temp;
//	int M;
//	scanf("%d", &M);
//
//	node* table;
//	table = (node*)malloc(sizeof(node) * M);
//	//��� �迭 �ʱ�ȭ �����ֱ�
//	for (int i = 0; i < M; i++) {
//		table[i].next = NULL;
//		table[i].data = 0;
//	}
//
//	char x = ' ';
//
//	while (x != 'e') {
//		scanf("%c", &x);
//		if (x == 'i') {
//			scanf("%d", &temp);
//			insertKey(table, M, temp );
//		}
//		else if (x == 's') {
//			scanf("%d", &temp);
//			searchKey(table, M, temp);
//		}
//		else if (x == 'd') {
//			scanf("%d", &temp);
//			deleteKey(table, M, temp);
//		}
//		else if (x == 'p') {
//			printTable(table,M);
//		}
//
//	}
//	
//
//}
//

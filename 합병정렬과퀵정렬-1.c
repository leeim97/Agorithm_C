//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//typedef struct node {
//	int ele;
//	struct node* next;
//}node;
//
//typedef struct list {
//	node* head;
//	int size;
//
//}list;
//
//
//list* mergeSort(list*);
//list* merge(list*, list*);
//int removeFirst(list*);
//int isEmpty(list*);
//node* getNode();
//list* partition(list* L, int k);
//void addLast(list* L,int ele);
//void print(list*);
//
//int main() {
//	int num;
//
//	scanf("%d", &num);
//	list* newL=NULL;
//	list* L = (list*)malloc(sizeof(list));
//	node* p;
//	L->size = 0;
//	L->head = getNode();
//	p = L->head;
//
//	for (int i = 0; i < num; i++) {
//		int temp;
//		node* q=getNode();
//		scanf("%d", &temp);
//		q->ele = temp;
//		p->next = q;
//		p = p->next;
//		L->size++;
//	}
//	
//	newL=mergeSort(L);
//	print(newL);
//
//
//
//}
//list* setList() {
//	list* L = (list*)malloc(sizeof(list));
//	L->head = getNode();
//	L->size = 0;
//
//	return L;
//}
//
//node* getNode() {
//	node* newnode;
//	newnode = (node*)malloc(sizeof(node));
//	newnode->next = NULL;
//	newnode->ele = 0;
//
//	return newnode;
//
//}
//list* partition(list* L, int k) {
//	node* p = L->head;
//	list* L2;
//	L2 = setList();
//
//	for (int i = 1; i <= k; i++) {
//		p = p->next;
//	}
//
//	node* L1lastnode = p;
//
//	L2->head->next = p->next;
//	L1lastnode->next = NULL;
//
//	L2->size = (L->size)-k;
//	L->size = k;
//	return L2;
//}
//
//list* mergeSort(list* L) {
//	list* L1;
//	list* L2;
//	list* L3=(list*)malloc(sizeof(list));
//	if (L->size > 1) {
//		L2 = partition(L, ((L->size) / 2));
//		L1 = mergeSort(L);
//		L2 = mergeSort(L2);
//		L3 = merge(L1, L2);
//		return L3;
//	}
//	else
//		return L;
//}
//list* merge(list* L1, list*L2) {
//	list* L;
//	L = setList();
//	while (!isEmpty(L1) && !isEmpty(L2)) {
//		if (L1->head->next->ele <= L2->head->next->ele) {
//			addLast(L, removeFirst(L1));
//		}
//		else
//			addLast(L, removeFirst(L2));
//	}
//
//	while (!isEmpty(L1)) {	
//			addLast(L, removeFirst(L1));	
//	}
//
//	
//	while (!isEmpty(L2)) {	
//			addLast(L, removeFirst(L2));
//	}
//
//	return L;
//}
//
//void addLast(list* L,int ele) {
//	node* p = L->head;
//	node* newnode = getNode();
//	while (p->next != NULL) {
//		p = p->next;
//	}
//
//	p->next = newnode;
//	newnode->ele = ele;
//	L->size++;
//
//}
//
//int removeFirst(list*L) {
//	node* p = L->head;
//	node* temp;
//	int num;
//	
//	temp = p->next;
//	num= temp->ele;
//	L->size -= 1;
//
//	p->next = temp->next;
//	free(temp);
//
//
//	return num;
//
//};
//int isEmpty(list*L ) {
//	if (L->size <= 0)
//		return 1;
//	else
//		return 0;
//};
//
//void print(list* L) {
//
//	node* p = L->head;
//
//	while (p->next != NULL) {
//		p = p->next;
//		
//		printf(" %d", p->ele);
//	}
//	
//}

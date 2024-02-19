//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define true 1
//#define false 0
//#define noSuchKey -1
//
//typedef struct treeNode {
//	int key;
//	struct treeNode* parent;
//	struct treeNode* left;
//	struct treeNode* right;
//}node;
//
//
//node* root;
//
//int isExternal(node* w);
//int isInternal(node* w);
//int isRoot(node* w);
//node* sibling(node* w);
//void expandExternal(node* w);
//node* reduceExternal(node* z);
//node* treeSearch(node* v, int k);
//int findElement(int k);
//void insertItem(int k);
//node* inOrderSucc(node* w);
//int removeElement(int k);
//void printPreOrder(node* w);
//node* getNode();
//
//int main() {
//	char ch=' ';
//	
//	root = getNode();
//	
//
//	while (ch != 'q') {
//		scanf(" %c", &ch);
//		int num;
//
//		if (ch == 'i') {
//			scanf(" %d", &num);
//			//getchar();
//			insertItem(num);
//		}
//		else if (ch == 'd') {
//			scanf(" %d", &num);
//			//getchar();
//			
//			int result = removeElement(num);
//			if (result == noSuchKey) {
//				printf("X\n");
//			}
//			else if (result != noSuchKey) {
//				printf("%d\n", result);
//				
//			}
//			
//		}
//		else if (ch == 's') {
//			scanf(" %d", &num);
//			//getchar();
//			int result = findElement(num);
//			if (result == noSuchKey)
//				printf("X\n");
//			else if((result != noSuchKey))
//				printf("%d\n", result);
//		}
//		else if (ch == 'p') {
//			printPreOrder(root);
//			printf("\n");
//		}
//	}
//
//}
//
//node* getNode() {
//	
//	node* p = (node*)malloc(sizeof(node));
//	p->parent = NULL;
//	p->left = NULL;
//	p->right = NULL;
//	p->key = 0;
//
//	return p;
//}
//void printPreOrder(node* w) {
//	if (isExternal(w)) return;
//
//	printf(" %d", w->key);
//	printPreOrder(w->left);
//	printPreOrder(w->right);
//}
//
//int isExternal(node* w) {
//	
//	if (w->left == NULL && w->right == NULL)
//		return 1;
//	else
//		return 0;
//}
//
//int isInternal(node* w) {
//
//	if (w->left != NULL || w->right != NULL)
//		return 1;
//	else
//		return 0;
//
//}
//
//int isRoot(node* w) {
//	if (w->parent == NULL)
//		return 1;
//	else
//		return 0;
//}
//
//node* sibling(node* w) {
//	if (isRoot(w))
//		printf("don't have sibling");
//
//	if (w->parent->left == w) {
//		return w->parent->right;
//	}
//	else if (w->parent->right == w) {
//		return w->parent->left;
//	}
//}
//
//void expandExternal(node* w) {
//	node* l = getNode();
//	node* r = getNode();
//
//	l->parent = w;
//	r->parent = w;
//	w->left = l;
//	w->right = r;
//	return;
//}
//
//node* reduceExternal(node* z) {
//	node* w,*zs;
//	w = z->parent;
//	zs = sibling(z);
//
//	if (isRoot(w)) {
//		
//		root = zs;   //root라 안하고 w라고 했을때는 90점임 왜?
//		zs->parent = NULL;
//	}
//	else {
//		node* g = w->parent;
//		zs->parent = g;
//		if (w == g->left) {
//			g->left = zs;
//		}
//		else if (w == g->right) {
//			g->right = zs;
//		}
//	}
//
//	free(w);
//	free(z);
//
//	return zs;
//
//}
////treeSearch에서 조건문 k< v->key와 k> v->key를 바꿧을때 값이 다르게나오네?
//node* treeSearch(node* v, int k) {
//	if (isExternal(v)) return v;
//
//	if (v->key == k)
//		return v;
//
//	else if (k< v->key )
//		return treeSearch(v->left, k);
//
//	else if (k> v->key )
//		return treeSearch(v->right, k);
//}
//
//int findElement(int k) {
//	node* w = treeSearch(root, k);
//
//	if (isExternal(w))
//		return noSuchKey;
//	else
//		return w->key;
//}
//
//void insertItem(int k) {
//	node* w = treeSearch(root, k);
//
//	if (isInternal(w))
//		return ;
//	else {
//		expandExternal(w);
//		w->key = k;
//		return ;
//		
//	}
//
//
//}
//
//node* inOrderSucc(node* w) {
//	node* p;
//
//	p = w->right;
//
//	if (isExternal(p))
//		printf("invalidNodeExeception");
//	
//	while (isInternal(p->left)) {
//		p = p->left;
//	}
//
//	return p;
//
//}
//
//int removeElement(int k) {
//	node* w = treeSearch(root, k);
//
//	if (isExternal(w))
//		return noSuchKey ;
//
//	int ele = w->key;
//
//	node* z = w->left;
//	if (!isExternal(z))
//		z = w->right;
//
//	if (isExternal(z)) {
//		reduceExternal(z);
//	}
//	else 
//	{
//		node* y = inOrderSucc(w);
//		z = y->left;
//		w->key = y->key;
//		reduceExternal(z);
//	}
//
//	return ele;
//}
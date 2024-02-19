//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define true 1
//#define false 0
//#define noSuchKey -1
//#define max(a,b) (((a) > (b))? (a):(b))
//
//typedef struct treeNode {
//	int key;
//	struct treeNode* parent;
//	struct treeNode* left;
//	struct treeNode* right;
//	int height;
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
//node* inOrderSucc(node* w);
//
//int updateHeight(node* w);
//int isBalanced(node* w);
//node* restructure(node* x, node* y, node* z);
//void searchAndFixAfterInsertion(node* w);
//void insertItem(int k);
////void searchAndFixAfterRemoval(node* w);
////int removeElement(int k);
//void printPreOrder(node* w);
//
//node* getNode();
//
//int main() {
//	char ch = ' ';
//
//	root = getNode();
//
//
//	while (ch != 'q') {
//		scanf("%c", &ch);
//		getchar();
//		int num;
//
//		if (ch == 'i') {
//			scanf("%d", &num);
//
//			insertItem(num);
//			printf("root=%d\n", root->key);
//			getchar();
//		}
//		/*else if (ch == 'd') {
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
//		}*/
//		else if (ch == 's') {
//			scanf("%d", &num);
//
//			int result = findElement(num);
//			if (result == noSuchKey)
//				printf("X\n");
//			else if ((result != noSuchKey))
//				printf("%d\n", result);
//			getchar();
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
//	p->height = 0;
//
//	return p;
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
//		return;
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
//	w->height = 1;
//	return;
//}
//
//node* reduceExternal(node* z) {
//	node* w, * zs;
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
//	else if (k < v->key)
//		return treeSearch(v->left, k);
//
//	else if (k > v->key)
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
//node* inOrderSucc(node* w) {
//
//
//	w = w->right;
//
//	if (isExternal(w))
//		return;
//
//	while (isInternal(w->left)) {
//		w = w->left;
//	}
//
//	return w;
//
//}
//
//int updateHeight(node* w) {
//	int height=w->height;
//
//	if (w->left->height > w->right->height) {
//		height = w->left->height + 1;
//	}
//	else if (w->left->height < w->right->height) {
//		height = w->right->height + 1;
//	}
//
//	if (w->height != height) {
//		w->height = height;
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int isBalanced(node* w) {
//
//	if ((-1 <= (w->left->height - w->right->height)) && ((w->left->height - w->right->height) <= 1))
//		return 1;
//	else
//		return 0;
//
//}
//
//node* restructure(node* x, node* y, node* z) {
//	node* a, * b, * c;
//	node* T0, * T1, * T2, * T3;
//
//	if ((z->key < y->key) && (y->key < x->key)) {
//		a = z;
//		b = y;
//		c = x;
//
//		T0 = a->left;
//		T1 = b->left;
//		T2 = c->left;
//		T3 = c->right;
//
//	}
//	else if ((x->key < y->key) && (y->key < z->key)) {
//		a = x;
//		b = y;
//		c = z;
//		T0 = a->left;
//		T1 = a->right;
//		T2 = b->right;
//		T3 = c->right;
//	}
//	else if ((z->key < x->key) && (x->key < y->key)) {
//
//		a = z;
//		b = x;
//		c = y;
//		T0 = a->left;
//		T1 = b->left;
//		T2 = b->right;
//		T3 = c->right;
//
//	}
//	else {
//		a = y;
//		b = x;
//		c = z;
//
//		T0 = a->left;
//		T1 = b->left;
//		T2 = b->right;
//		T3 = c->right;
//	}
//
//
//
//	if (isRoot(z)) {
//		root = b;
//		printf("ok\n");
//		b->parent = NULL;
//	}
//
//
//	else if (z->parent->left == z) {
//
//		z->parent->left = b;
//
//		b->parent = z->parent;
//	}
//
//	else if (z->parent->right == z) {
//
//		z->parent->right = b;
//		b->parent = z->parent;
//
//	}
//
//
//	a->left = T0;
//	T0->parent = a;
//	a->right = T1;
//	T1->parent = a;
//	updateHeight(a);
//
//	c->left = T2;
//	T2->parent = c;
//	c->right = T3;
//	T3->parent = c;
//	updateHeight(c);
//
//	b->left = a;
//	a->parent = b;
//	b->right = c;
//	c->parent = b;
//	updateHeight(b);
//	return b;
//
//}
//
//void searchAndFixAfterInsertion(node* w) {
//	node* x, *y, * z;
//
//	w->left->height = 0;
//	w->right->height = 0;
//	w->height = 1;
//
//	if (isRoot(w)) {
//		return ;
//	}
//	z = w->parent;
//	while (updateHeight(z) && isBalanced(z)) {
//		if (isRoot(z)) {
//			return;
//		}
//		z = z->parent;
//	}
//
//	if (isBalanced(z)) {
//		return;
//	}
//
//	if (z->left->height > z->right->height) {
//		y = z->left;
//	}
//	else if (z->left->height <= z->right->height) {
//		y = z->right;
//	}
//
//	if (y->left->height > y->right->height) {
//		x = y->left;
//	}
//	else {
//		x = y->right;
//	}
//
//	restructure(x, y, z);
//	return;
//}
//
//void insertItem(int k) {
//
//	node* w = treeSearch(root, k);
//
//	if (isInternal(w))
//		return;
//	else {
//		w->key = k;
//		expandExternal(w);
//		searchAndFixAfterInsertion(w);
//
//
//	}
//
//}
//
///*void searchAndFixAfterRemoval(node* w) {
//
//}*/
//
//
//
///*int removeElement(int k) {
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
//}*/
//
//void printPreOrder(node* w) {
//	if (isExternal(w)) return;
//
//	printf(" %d", w->key);
//	printPreOrder(w->left);
//	printPreOrder(w->right);
//}

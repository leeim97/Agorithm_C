//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//#define fresh 0
//#define visited 1
//#define tree 1
//#define cross 2
//
//typedef struct edge {
//	int eLabel;
//	int vNum1, vNum2;
//	struct edge* next;
//}edge;
//
//edge* getEdge() {
//	edge* p = (edge*)malloc(sizeof(edge));
//	p->next = NULL;
//	p->vNum1 = 0;
//	p->vNum2 = 0;
//	p->eLabel = fresh;
//
//	return p;
//}
//
//
//typedef struct vertex {
//	int VNum;
//	int vLabel;
//	struct vertex* next;
//}vertex;
//
//vertex* getVertex() {
//	vertex* p = (vertex*)malloc(sizeof(vertex));
//	p->next = NULL;
//	p->VNum = 0;
//	p->vLabel = fresh;
//
//	return p;
//}
//
//typedef struct graph {
//	vertex* vertices;
//	edge* edges;
//	edge* adjmtx[101][101];
//}graph;
//
//void insertVertex(graph* graph, int vNumber) {
//	//���� ����Ʈ�� �տ� vNumber�� ������ ����(����x) �� ���� ����
//	vertex* p = getVertex();
//	p->VNum = vNumber;
//	p->vLabel = fresh;
//
//	vertex* q = graph->vertices;
//
//	if (q == NULL)
//		graph->vertices = p;
//	else {
//		p->next = q;
//		graph->vertices = p;
//	}
//}
//
//vertex* findVertex(graph* graph, int vNumber) {
//	//���� ����Ʈ�� ��ȸ�ϸ� vNumber�� ������ ���� ��� ã�Ƽ� ��ȯ, ������ NULL ��ȯ
//
//	vertex* p = graph->vertices;
//
//	while (p != NULL) {
//		if (p->VNum == vNumber)
//			return p;
//		p = p->next;
//	}
//
//	return NULL;
//}
//
//int opposite(edge* edge, int vNumber) {
//	//vNumber ������ �������� edge�� �ݴ��� ���� ��ȣ ��ȯ
//
//	if (edge->vNum1 == vNumber) {
//		return edge->vNum2;
//	}
//	else if (edge->vNum2 == vNumber) {
//		return edge->vNum1;
//	}
//}
//
//edge* findEdge(graph* graph, int vNumber1, int vNumber2) {
//	//��������Ʈ�� ��ȸ�ϸ� ���� ��ȣ vNumber1,vNumber2�� �����ϴ� ���� ��� ã�Ƽ� ��ȯ
//	//(vNumber1,vNumber2) (vNumber2,vNumber1) ��� ���
//
//	edge* p = graph->edges;
//
//
//	while (p != NULL) {
//		if ((p->vNum1 == vNumber1 && p->vNum2 == vNumber2) || (p->vNum1 == vNumber2 && p->vNum2 == vNumber1))
//			return p;
//		p = p->next;
//	}
//
//	return NULL;
//
//}
//
//void insertAdjacencyMatrix(graph* graph, int vNumber1, int vNumber2, edge* edge) {
//	graph->adjmtx[vNumber1][vNumber2] = edge;
//	graph->adjmtx[vNumber2][vNumber1] = edge;
//
//}
//
//
//void insertEdge(graph* graph, int vNumber1, int vNumber2) {
//	//���� ����Ʈ �տ� ���� vNumber1,vNumber2�� �����ϴ� �� ���� ����
//	//���� ���Խ� ���� vNumber1,vNumber2�� ��������Ʈ ������Ʈ(insertIncidentEdges)
//
//	edge* p = getEdge();
//	p->vNum1 = vNumber1;
//	p->vNum2 = vNumber2;
//	p->eLabel = fresh;
//
//
//	p->next = graph->edges;
//	graph->edges = p;
//
//	insertAdjacencyMatrix(graph, vNumber1, vNumber2, p);
//
//
//}
//
//
//void initialize(graph* graph, int numV, int numE) {
//	graph->edges = NULL;
//	graph->vertices = NULL;
//
//	for (int i = 1; i <= numV; i++) {
//		insertVertex(graph, i);
//	}
//
//	for (int j = 0; j < numE; j++) {
//		int vNum1, vNum2;
//		scanf("%d %d", &vNum1, &vNum2);
//		insertEdge(graph, vNum1, vNum2);
//	}
//
//}
//
//void BFSI(graph* graph, int s, int numV) {
//
//	//row 0: L0,row 1: L1,row 2:L2...
//	//L[i][0]==NULL : Li empty
//	vertex* L[100][100];
//	memset(L, NULL, sizeof(L));
//
//	/*
//		s ��ȣ ���� v�� ã�Ƽ� v�� ���� visited�� ����, s���,L0.addLast(v) (L[0][0]=v;)
//		Li: L[i][..], �� ���Ҵ� ����
//		incidentEdges(v):graph->adjmtx[v->vNum][j=1~numV]�� NULL�� �ƴ� ������(j:�ݴ� ���� ��ȣ)
//		������ visited�� ����� ������ �ش� ���� ��ȣ ���
//	*/
//	vertex* p = findVertex(graph, s);
//	L[0][0] = p;
//	p->vLabel = visited;
//	printf("%d\n", p->VNum);
//	int i = 0;
//	while (L[i][0] != NULL) { //L.i�� ����ִ��� Ȯ�� ��������� ��
//		L[i+1][0] = NULL; //L.i+1 �ʱ�ȭ
//		int j = 0; //j�� L.i�� ��Ҹ� ��Ÿ���� ����
//		int l = 0;//l�� ���ο� L.i+1�� �ֱ�����
//		while (L[i][j] != NULL) { //L.i�� ������Ʈ
//			
//			vertex* q = L[i][j];
//			
//			for (int k = 1; k <= numV; k++) {
//				
//				edge* e = graph->adjmtx[q->VNum][k]; //������ incidenEdge
//				if (e == NULL)		//������Ŀ���
//					continue;		//�ش��ϴ� ������ ���̸� �پ�ѱ�
//							
//
//				if (e->eLabel == fresh) {
//					vertex* w = findVertex(graph, opposite(e, q->VNum));
//					
//					if (w->vLabel == fresh) {
//						e->eLabel = tree;
//						w->vLabel = visited;
//						printf("%d\n", w->VNum);
//						L[i + 1][l] = w;
//						l++;
//					}
//					else {
//						e->eLabel = cross;
//					}
//				}
//				
//			}
//			j++;
//		}
//		i++;
//	}
//
//}
//
//void BFS(graph* graph, int s, int numV) {
//
//	/*
//		s:��� ���� ��ȣ
//		numV:�� ���� ����
//		1.���� ����Ʈ�� ��ȸ�ϸ� ��� ������ ���� fresh�� �ʱ�ȭ(�Ǵ� insertVertex����)
//		2.���� ����Ʈ�� ��ȸ�ϸ� ��� ������ ���� fresh�� �ʱ�ȭ(�Ǵ� insertEdge����)
//		BFSI(graph,s,numV);
//		*/
//
//	vertex* p = findVertex(graph, s);
//	if (p->vLabel == fresh) {
//		BFSI(graph, s, numV);
//	}
//}
//
//int main() {
//	graph* gra = (graph*)malloc(sizeof(graph));
//	int n, m, s;//n�� ������ ����,m�� ������ ����,s�� ���� ����
//
//	scanf("%d %d %d", &n, &m, &s);
//
//	initialize(gra, n, m);
//	BFS(gra, s, n);
//
//	free(gra);
//}
//

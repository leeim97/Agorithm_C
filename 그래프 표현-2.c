//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_SIZE 100
//
//typedef struct edge {
//	int w;
//	int vNum1, vNum2;
//	struct edge* next;
//}edge;
//
//edge* getEdge() {
//	edge* p = (edge*)malloc(sizeof(edge));
//	p->next = NULL;
//	p->vNum1 = 0;
//	p->vNum2 = 0;
//	p->w = 0;
//
//	return p;
//}
//
//
//typedef struct vertex {
//	int VNum;
//	struct vertex* next;
//}vertex;
//
//vertex* getVertex() {
//	vertex* p = (vertex*)malloc(sizeof(vertex));
//	p->next = NULL;
//	p->VNum = 0;
//
//	return p;
//}
//
//typedef struct graph {
//	vertex* vertices;
//	edge* edges;
//	edge* adjmtx[10][10];
//}graph;
//
//void insertVertex(graph* graph, int vNumber) {
//	//���� ����Ʈ�� �տ� vNumber�� ������ ����(����x) �� ���� ����
//	vertex* p = getVertex();
//	p->VNum = vNumber;
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
//void insertEdge(graph* graph, int vNumber1, int vNumber2, int weight) {
//	//���� ����Ʈ �տ� ���� vNumber1,vNumber2�� �����ϴ� �� ���� ����
//	//���� ���Խ� ���� vNumber1,vNumber2�� ��������Ʈ ������Ʈ(insertIncidentEdges)
//
//	edge* p = getEdge();
//	p->vNum1 = vNumber1;
//	p->vNum2 = vNumber2;
//	p->w = weight;
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
//void deleteEdge(graph* graph, int vNumber1, int vNumber2) {
//	//0.���� vNumber1,vNumber2�� �����ϴ� ���� ��� dEdge ã��
//	//1.��������Ʈ���� dEdge ����
//	//2.������� ������Ʈ: ������ ��ġ�� NULL ����
//
//	edge* d = findEdge(graph, vNumber1, vNumber2);
//	if (d == NULL) {
//		return;
//	}
//
//	edge* p = graph->edges;
//	edge* prev = NULL;
//	while (p != NULL) {
//		if (p == d) {
//			if (prev != NULL) {
//				prev->next = d->next;
//			}
//			else {
//				graph->edges = d->next;
//			}
//			break;
//		}
//		prev = p;
//		p = p->next;
//	}
//
//	insertAdjacencyMatrix(graph, vNumber1, vNumber2, NULL);
//	free(d);
//
//
//}
//
//
//void processA(graph* graph, int a) {
//	//1.a ������ ã��,a ������ ��������Ʈ�� ������ -1 ���
//	//��������� [a][i] �Ǵ� [i][a]�� ���󰡸� ���� ������ ã��(i=1~10)
//	//2-1.���� ������ �ݴ��� ������ȣ ���
//	//2-2.���������� ����ġ ���
//	
//	vertex* p = findVertex(graph, a);
//	if (p == NULL)
//		return printf("%d", -1);
//	
//	
//	for (int i = 1; i <=10; i++) {
//		if (graph->adjmtx[a][i] != NULL) {
//			printf(" %d", i);
//			printf(" %d\n", graph->adjmtx[a][i]->w);
//		}
//		
//	}
//}
//
//
//void processM(graph* graph, int a, int b, int ww) {
//	vertex* p1 = findVertex(graph, a);
//	vertex* p2 = findVertex(graph, b);
//	if (p1 == NULL || p2 == NULL)
//		return printf("-1");
//
//	edge* p = findEdge(graph, a, b);
//
//	if (p == NULL) {
//		insertEdge(graph, a, b, ww);
//	}
//	else {
//		if (ww != 0) {
//			p->w = ww;
//		}
//		else
//			deleteEdge(graph, a, b);
//	}
//}
//
//void initialize(graph* graph) {
//	graph->edges = NULL;
//	graph->vertices = NULL;
//	insertVertex(graph, 6);
//	insertVertex(graph, 5);
//	insertVertex(graph, 4);
//	insertVertex(graph, 3);
//	insertVertex(graph, 2);
//	insertVertex(graph, 1);
//
//	insertEdge(graph, 6, 1, 2);
//	insertEdge(graph, 6, 5, 3);
//	insertEdge(graph, 5, 5, 4);
//	insertEdge(graph, 5, 3, 4);
//	insertEdge(graph, 3, 1, 1);
//	insertEdge(graph, 3, 2, 1);
//	insertEdge(graph, 2, 1, 1);
//	insertEdge(graph, 1, 4, 1);
//
//}
//
//int main() {
//
//	int temp;
//	char ch = ' ';
//	graph* gra;
//	gra = (graph*)malloc(sizeof(graph));
//	initialize(gra);
//	while (ch != 'q') {
//		scanf(" %c", &ch);
//
//
//		if (ch == 'a') {
//			scanf("%d", &temp);
//			processA(gra, temp);
//		}
//		else if (ch == 'm') {
//			int vNumber1, vNumber2, weight;
//
//			scanf("%d %d %d", &vNumber1, &vNumber2, &weight);
//			processM(gra, vNumber1, vNumber2, weight);
//		}
//	}
//
//}
//

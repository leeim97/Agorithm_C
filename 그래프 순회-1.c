//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define fresh 0
//#define visited 1
//#define tree 1
//#define back 2
//
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
//	p->eLabel =fresh;
//
//	return p;
//}
//
//typedef struct incidentEdge {
//	edge* edge;
//	struct incidentEdge* next;
//
//}incidentEdge;
//
//incidentEdge* getIncidentEdge() {
//	incidentEdge* p = (incidentEdge*)malloc(sizeof(incidentEdge));
//
//	p->edge = NULL;
//	p->next = NULL;
//
//	return p;
//}
//
//typedef struct vertex {
//	int VNum;
//	incidentEdge* iEdges;
//	struct vertex* next;
//	int vLabel;
//}vertex;
//
//vertex* getVertex() {
//	vertex* p = (vertex*)malloc(sizeof(vertex));
//	p->next = NULL;
//	p->iEdges = NULL;
//	p->VNum = 0;
//	p->vLabel = fresh;
//
//	return p;
//}
//
//typedef struct graph {
//	vertex* vertices;
//	edge* edges;
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
//void insertOneIncidentEdge(graph* graph, int vNumber, edge* edge) {
//	//vNumber ������ ��������Ʈ�� Edge�� �ּҸ� ������ ��������Ʈ ��� ����
//	//������������Ʈ�� �ݴ��� ���� ��ȣ������ ������������ ���ĵǵ��� ����
//
//	/*
//		vNumber�� ������ ����ã��
//		������ ��������Ʈ�� ��ȸ�ϸ�,
//		oppsite(��ȸ ����� edge,vNumber),opposite(Edge,vNumber)���ϸ�
//		Edge�� ����Ű�� �� ��������Ʈ ��带 ������ ����
//	*/
//	vertex* p = findVertex(graph, vNumber);
//
//	incidentEdge* newIe = getIncidentEdge();
//	newIe->edge = edge;
//
//	incidentEdge* ie = p->iEdges;
//	if (ie == NULL) {
//		p->iEdges = newIe;
//		return;
//	}
//
//	incidentEdge* prev = NULL;
//	while (ie != NULL) {
//		int op = opposite(ie->edge, vNumber);
//		int newOp = opposite(newIe->edge, vNumber);
//
//		if (newOp < op) {
//			newIe->next = ie;
//			if (prev != NULL) {
//				prev->next = newIe;
//			}
//			else {
//				p->iEdges = newIe;
//			}
//			return;
//		}
//
//		prev = ie;
//		ie = ie->next;
//	}
//
//	// ���� ���� ū���϶�
//	prev->next = newIe;
//}
//
//
//
//void insertIncidentEdges(graph* graph, int vNumber1, int vNumber2, edge* edge) {
//	//insertOneIncidentEdge ���
//	//Edge�� ������ ���:vNumber1 ������ ��������Ʈ ������Ʈ
//	//Edge�� ������ �ƴ� ���: vNumber1 ������ ��������Ʈ & vNumber2 ������ ��������Ʈ ������Ʈ
//	insertOneIncidentEdge(graph, vNumber1, edge);
//	if (vNumber1 != vNumber2) {
//		insertOneIncidentEdge(graph, vNumber2, edge);
//	}
//
//}
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
//	insertIncidentEdges(graph, vNumber1, vNumber2, p);
//
//
//}
//
//
//void initialize(graph* graph,int numV,int numE) {
//	/*
//	���� ����: ���� ��ȣ 1~numV�� ������ ���� numV�� ����
//	���� ����: �糡 ���� ��ȣ �� ���� �Է¹޾� �ش� �糡 ������ �����ϴ� ���� �� numE�� ����
//	*/
//	graph->edges = NULL;
//	graph->vertices = NULL;
//
//	for (int i = 1; i <= numV; i++) {
//		insertVertex(graph, i);
//	}
//	
//	
//	for (int j = 0; j < numE; j++) {
//		int vNumber1, vNumber2;
//		scanf("%d %d", &vNumber1, &vNumber2);
//		insertEdge(graph, vNumber1, vNumber2);
//	}
//}
//
//void rDFS(graph* graph, int s) {
//	/*
//	1.s ��ȣ ���� v�� ã�Ƽ� v�� ���� visited�� ����, s ���
//	2.v�� ��������Ʈ�� ��ȸ�ϸ� �������� e , �ݴ� ���� w�� ���� �ʿ� �ڵ� �ۼ�
//	*/
//	vertex* w;
//	vertex* p=findVertex(graph, s);
//	p->vLabel = visited;
//	printf("%d\n", s);
//
//	incidentEdge* e = p->iEdges;
//
//	while (e != NULL) {
//		if (e->edge->eLabel == fresh) {
//			w = findVertex(graph, opposite(e->edge, s));
//			if (w->vLabel == fresh) {
//				e->edge->eLabel = tree;
//				rDFS(graph, w->VNum);
//			}
//			else
//				e->edge->eLabel = back;
//		}
//		e = e->next;
//	}
//	
//
//}
//
//void DFS(graph* graph, int s) {
//	/*
//		s:��� ���� ��ȣ
//		1.���� ����Ʈ�� ��ȸ�ϸ� ��� ������ ���� fresh�� �ʱ�ȭ(�Ǵ� insertVertex���� fresh ����)
//		2.���� ����Ʈ�� ��ȸ�ϸ� ��� ������ ���� fresh�� �ʱ�ȭ(�Ǵ� insertEdge���� fresh ����)
//		rDFS(graph, s);
//	*/
//
//	vertex* p = findVertex(graph, s);
//	if (p->vLabel == fresh) {
//		rDFS(graph, s);
//	}
//
//
//}
//
//int main() {
//
//	graph* gra;
//	gra = (graph*)malloc(sizeof(graph));
//
//
//	int n, m, s; // n�� ������ ����,m�� ������ ����,.s�� �������� ��ȣ
//	scanf("%d %d %d", &n, &m, &s);
//
//	initialize(gra, n, m);
//
//	DFS(gra, s);
//}
//

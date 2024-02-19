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
//	//정점 리스트의 앞에 vNumber를 가지는 고립된(연결x) 새 정점 삽입
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
//	//정점 리스트를 순회하며 vNumber를 가지는 정점 노드 찾아서 반환, 없으면 NULL 반환
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
//	//간선리스트를 순회하며 정점 번호 vNumber1,vNumber2를 연결하는 간선 노드 찾아서 반환
//	//(vNumber1,vNumber2) (vNumber2,vNumber1) 모두 고려
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
//	//간선 리스트 앞에 정점 vNumber1,vNumber2를 연결하는 새 간선 삽입
//	//간선 삽입시 정점 vNumber1,vNumber2의 부착리스트 업데이트(insertIncidentEdges)
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
//	//0.정점 vNumber1,vNumber2를 연결하는 간선 노드 dEdge 찾기
//	//1.간선리스트에서 dEdge 삭제
//	//2.인접행렬 업데이트: 적절한 위치에 NULL 저장
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
//	//1.a 정점을 찾고,a 정점이 정점리스트에 없으면 -1 출력
//	//인접행렬의 [a][i] 또는 [i][a]를 따라가며 부착 간선을 찾아(i=1~10)
//	//2-1.부착 간선의 반대편 정점번호 출력
//	//2-2.부착간선의 가중치 출력
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

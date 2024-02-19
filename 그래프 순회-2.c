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
//	//정점 리스트의 앞에 vNumber를 가지는 고립된(연결x) 새 정점 삽입
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
//int opposite(edge* edge, int vNumber) {
//	//vNumber 정점의 부착간선 edge의 반대편 정점 번호 반환
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
//void insertEdge(graph* graph, int vNumber1, int vNumber2) {
//	//간선 리스트 앞에 정점 vNumber1,vNumber2를 연결하는 새 간선 삽입
//	//간선 삽입시 정점 vNumber1,vNumber2의 부착리스트 업데이트(insertIncidentEdges)
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
//		s 번호 정점 v를 찾아서 v의 라벨을 visited로 변경, s출력,L0.addLast(v) (L[0][0]=v;)
//		Li: L[i][..], 각 원소는 정점
//		incidentEdges(v):graph->adjmtx[v->vNum][j=1~numV]중 NULL이 아닌 간선들(j:반대 정점 번호)
//		정점이 visited로 변경될 때마다 해당 정점 번호 출력
//	*/
//	vertex* p = findVertex(graph, s);
//	L[0][0] = p;
//	p->vLabel = visited;
//	printf("%d\n", p->VNum);
//	int i = 0;
//	while (L[i][0] != NULL) { //L.i가 비어있는지 확인 비어있으면 끝
//		L[i+1][0] = NULL; //L.i+1 초기화
//		int j = 0; //j는 L.i의 요소를 나타내기 위해
//		int l = 0;//l은 새로운 L.i+1에 넣기위해
//		while (L[i][j] != NULL) { //L.i의 엘레멘트
//			
//			vertex* q = L[i][j];
//			
//			for (int k = 1; k <= numV; k++) {
//				
//				edge* e = graph->adjmtx[q->VNum][k]; //각각의 incidenEdge
//				if (e == NULL)		//인접행렬에서
//					continue;		//해당하는 엣지가 널이면 뛰어넘기
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
//		s:출발 정점 번호
//		numV:총 정점 개수
//		1.정점 리스트를 순회하며 모든 정점의 라벨을 fresh로 초기화(또는 insertVertex에서)
//		2.간선 리스트를 순회하며 모든 정점의 라벨을 fresh로 초기화(또는 insertEdge에서)
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
//	int n, m, s;//n은 정점의 개수,m은 간선의 개수,s는 시작 정점
//
//	scanf("%d %d %d", &n, &m, &s);
//
//	initialize(gra, n, m);
//	BFS(gra, s, n);
//
//	free(gra);
//}
//

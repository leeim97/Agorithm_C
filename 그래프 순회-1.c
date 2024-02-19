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
//void insertOneIncidentEdge(graph* graph, int vNumber, edge* edge) {
//	//vNumber 정점의 부착리스트에 Edge의 주소를 가지는 부착리스트 노드 삽입
//	//부착간선리스트의 반대쪽 정점 번호에대해 오름차순으로 정렬되도록 삽입
//
//	/*
//		vNumber를 가지는 정점찾기
//		정점의 부착리스트를 순회하며,
//		oppsite(순회 노드의 edge,vNumber),opposite(Edge,vNumber)비교하며
//		Edge를 가르키는 새 부착리스트 노드를 적절히 삽입
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
//	// 값이 가장 큰거일때
//	prev->next = newIe;
//}
//
//
//
//void insertIncidentEdges(graph* graph, int vNumber1, int vNumber2, edge* edge) {
//	//insertOneIncidentEdge 사용
//	//Edge가 루프인 경우:vNumber1 정점의 부착리스트 업데이트
//	//Edge가 루프가 아닌 경우: vNumber1 정점의 부착리스트 & vNumber2 정점의 부착리스트 업데이트
//	insertOneIncidentEdge(graph, vNumber1, edge);
//	if (vNumber1 != vNumber2) {
//		insertOneIncidentEdge(graph, vNumber2, edge);
//	}
//
//}
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
//	insertIncidentEdges(graph, vNumber1, vNumber2, p);
//
//
//}
//
//
//void initialize(graph* graph,int numV,int numE) {
//	/*
//	정점 삽입: 정점 번호 1~numV를 가지는 정점 numV개 삽입
//	간선 삽입: 양끝 정점 번호 두 개를 입력받아 해당 양끝 정점을 연결하는 간선 총 numE개 삽입
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
//	1.s 번호 정점 v를 찾아서 v의 라벨을 visited로 변경, s 출력
//	2.v의 부착리스트를 순회하며 부착간선 e , 반대 정점 w에 대해 필요 코드 작성
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
//		s:출발 정점 번호
//		1.정점 리스트를 순회하며 모든 정점의 라벨을 fresh로 초기화(또는 insertVertex에서 fresh 설정)
//		2.간선 리스트를 순회하며 모든 간선의 라벨을 fresh로 초기화(또는 insertEdge에서 fresh 설정)
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
//	int n, m, s; // n은 정점의 개수,m은 간선의 개수,.s는 시작정점 번호
//	scanf("%d %d %d", &n, &m, &s);
//
//	initialize(gra, n, m);
//
//	DFS(gra, s);
//}
//

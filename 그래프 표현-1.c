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
//}vertex;
//
//vertex* getVertex() {
//	vertex* p = (vertex*)malloc(sizeof(vertex));
//	p->next = NULL;
//	p->iEdges = NULL;
//	p->VNum = 0;
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
//	insertIncidentEdges(graph, vNumber1, vNumber2, p);
//
//
//}
//
//void deleteEdge(graph* graph, int vNumber1, int vNumber2) {
//	//0.정점 vNumber1,vNumber2를 연결하는 간선 노드 dEdge 찾기
//	//1.간선리스트에서 dEdge 삭제
//	//2.vNumber1 정점,vNumber2 정점의 부착리스트에서 dEdge를 가르키는 부착리스트 노드 삭제
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
//	vertex* q1 = findVertex(graph, vNumber1);
//	vertex* q2 = findVertex(graph, vNumber2);
//
//	incidentEdge* i1 = q1->iEdges;
//	incidentEdge* i2 = q2->iEdges;
//	incidentEdge* prevI1 = NULL;
//	incidentEdge* prevI2 = NULL;
//
//	while (i1 != NULL) {
//		if (i1->edge == d) {
//			if (prevI1 != NULL) {
//				prevI1->next = i1->next;
//			}
//			else {
//				q1->iEdges = i1->next;
//			}
//			free(i1);
//			break;
//		}
//		prevI1 = i1;
//		i1 = i1->next;
//	}
//
//	while (i2 != NULL) {
//		if (i2->edge == d) {
//			if (prevI2 != NULL) {
//				prevI2->next = i2->next;
//			}
//			else {
//				q2->iEdges = i2->next;
//			}
//			free(i2);
//			break;
//		}
//		prevI2 = i2;
//		i2 = i2->next;
//	}
//
//	free(d);
//}
//
//
//void processA(graph* graph, int a) {
//	//1.a 정점을 찾고,a 정점이 정점리스트에 없으면 -1 출력
//	//a 정점의 부착리스트의 노드를 순회하며,
//	//2-1.부착리스트 노드가 가르키는 간선의 반대편(oppsite 사용) 정점 번호 출력
//	//2-2.부착리스트 노드가 가르키는 간선의 가중치 출력
//	//(부착리스트가 간선의 반대편 정점 번호에 대해 오름차순으로 정렬되어있음)
//	vertex* p = findVertex(graph, a);
//	if (p == NULL)
//		return printf("%d", -1);
//
//	incidentEdge* pi = p->iEdges;
//
//
//
//	while (pi != NULL) {
//		printf(" %d", opposite(pi->edge, a));
//		printf(" %d", pi->edge->w);
//		pi = pi->next;
//	}
//	printf("\n");
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

//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define NUMV_MAX 100
//#define IN -1
//#define OUT 1
//
//typedef struct Edge {			//간선 노드
//	int orgIdx;					//시점 정점 인덱스
//	int desIdx;					//종점 정점 인덱스
//}edge;
//
//
//
//typedef struct IncidentEdge {	//부착리스트 노드
//	int edgeIdx;				//부착간선 인덱스
//	struct IncidentEdge* next;
//}incidentEdge;
//
//
//typedef struct Vertex {			//정점 노드
//	char vName;					//정점 이름
//	int inDegree;				//진입 차수
//	incidentEdge* InIEdges;		//진입 부착리스트(연결리스트)
//	incidentEdge* OutIEdges;	//진출 부착리스트(연결리스트)
//}vertex;
//
//typedef struct Graph {
//	vertex* vertices;			//정점 리스트(배열)
//	edge* edges;				//간선 리스트(배열)
//}graph;
//
//typedef struct Node {			//큐 노드
//	int vIdx;					//정점 인덱스
//	struct Node* next;
//}node;
//
//typedef struct Queue {
//	node* front;				//큐 삭제 지점
//	node* rear;					//큐 삽입 지점
//}queue;
//
////전역 변수
//graph G;						//방향 그래프							
//int n, m;						//정점, 간선 수
//int topOrder[NUMV_MAX + 1];		//DAG여부[0], 위상순서[1:n]
//queue Q;						//정점 대기용 큐
//
//void initQueue() {
//	Q.front = NULL;
//	Q.rear = NULL;
//};
//
//vertex getVertex() {
//	vertex p;
//	p.vName = ' ';
//	p.inDegree = 0;
//	p.InIEdges = NULL;
//	p.OutIEdges = NULL;
//
//	return p;
//}
//
//incidentEdge* getIncidentEdge() {
//	incidentEdge* p = (incidentEdge*)malloc(sizeof(incidentEdge));
//	p->edgeIdx = 0;
//	p->next = NULL;
//
//	return p;
//}
//
//node* getNode() {
//	node* p = (node*)malloc(sizeof(node));
//	p->next = NULL;
//	p->vIdx = 0;
//
//	return p;
//}
//
//// 그래프 정점 리스트(배열)의 vIdx 위치에 vName의 새로운 vertex 삽입
//void insertVertex(char vName, int vIdx) {
//	vertex p=getVertex();
//	p.vName = vName;
//
//	G.vertices[vIdx] = p;
//
//}
//
//// 그래프 정점 리스트(배열)에서 vName에 해당하는 정점의 인덱스를 반환
//int index(char vName) {
//	for (int i = 0; i < n; i++) {
//		if (G.vertices[i].vName == vName) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//// eIdx를 저장하는 새로운 인접간선 노드를 vIdx 정점의 부착리스트의 제일 앞에 삽입
//// in_or_out == IN: 진입 부착리스트에. in_or_out == OUT: 진출 부착리스트에 삽입
//void insertIncidentEdge(int vIdx, int eIdx, int in_or_out) {
//
//	if (in_or_out == IN) {
//		incidentEdge* q = G.vertices[vIdx].InIEdges;
//		incidentEdge* p = getIncidentEdge();
//		if (q == NULL) {
//			p->edgeIdx = eIdx;
//			p->next = NULL;
//			G.vertices[vIdx].InIEdges = p;
//		}
//		else {
//			p->edgeIdx = eIdx;
//			p->next = q;
//			G.vertices[vIdx].InIEdges = p;
//
//		}
//		G.vertices[vIdx].inDegree++;
//	}
//	else if (in_or_out == OUT) {
//		incidentEdge* q = G.vertices[vIdx].OutIEdges;
//		incidentEdge* p = getIncidentEdge();
//		if (q == NULL) {
//			p->edgeIdx = eIdx;
//			p->next = NULL;
//			G.vertices[vIdx].OutIEdges = p;
//		}
//		else {
//			p->edgeIdx = eIdx;
//			p->next = q;
//			G.vertices[vIdx].OutIEdges = p;
//			
//		}
//	}
//}
//
////그래프 초기화, 정점 n개 입력 ,간선 m개 입력
//void buildGraph() {
//
//	char vName;
//	scanf("%d", &n);
//	G.vertices = (vertex*)malloc(sizeof(vertex) * n);
//	
//
//	for (int i = 0; i < n; i++) {
//		
//		scanf(" %c", &vName);
//		
//		insertVertex(vName, i);
//	}
//
//	scanf("%d", &m);
//	G.edges = (edge*)malloc(sizeof(edge) * m);
//
//	char v1, v2;
//	for (int i = 0; i < m; i++) {
//		scanf(" %c %c", &v1, &v2);
//		G.edges[i].orgIdx = index(v1);	//진입 정점
//		insertIncidentEdge(index(v1), i, OUT); //진출 부착리스트에 들어가려고 v2
//		G.edges[i].desIdx = index(v2);	//진출 정점
//		insertIncidentEdge(index(v2), i, IN);//진입 부착리스트에 들어가려고 v1
//	}
//
//
//
//}
//
////큐가 비어있는지 확인(front==NULL이면 큐가 비어있음)
//int isEmpty() {
//	return Q.front == NULL;
//}
//
////정점 인덱스 vIdx를 큐의 rear에 삽입(첫 삽입에는 front에도 삽입)
//void enqueue(int vIdx) {
//	node* p = getNode();
//	p->vIdx = vIdx;
//	if (Q.front == NULL) {
//		Q.front = p;
//		Q.rear = p;
//	}
//	else {
//		Q.rear->next=p;
//		Q.rear = p;
//		
//	}
//
//}
//
////큐의 front에서 정점 인덱스 삭제 및 반환
//int dequeue(void) {
//	int value;
//	node* p = Q.front;
//	value = p->vIdx;
//
//	Q.front = Q.front->next;
//	free(p);
//	return value;
//}
//
////교재 의사코드 및 문제 파일 참조
////in 배열(in[i]: 정점 i의 진입차수) 사용, 정점 번호 순으로 전체 진입차수 조사,
////위상 순서배열 topSort 업데이트
//void topologicalSort() {
//	initQueue();
//	int* in = (int*)malloc(n * sizeof(int));
//
//	for (int i = 0; i < n; i++) {
//		vertex p = G.vertices[i];
//		in[i] = p.inDegree;
//		if (in[i] == 0)
//			enqueue(i);
//	}
//	int i = 1;
//
//	while (!isEmpty()) {
//		int de = dequeue();
//		vertex p = G.vertices[de];
//		topOrder[i] = de;//위상순서에 정점의 인덱스를 넣기
//		i = i + 1;
//		incidentEdge* ie = p.OutIEdges;
//
//		while (ie != NULL) {
//			edge ed = G.edges[ie->edgeIdx];
//			int w = ed.desIdx;
//			in[w] = in[w] - 1;
//			if (in[w] == 0)
//				enqueue(w);
//			ie = ie->next;
//		}
//	}
//		if (i <= n)
//			topOrder[0] = 0;
//		else
//			topOrder[0] = 1;
//	
//		
//
//
//	return;
//}
//
//int main() {
//	
//	buildGraph();
//
//	topologicalSort();
//
//	if (topOrder[0] == 0)
//		printf("%d", 0);
//	else {
//		for (int i = 1; i <= n; i++) {
//			int idx = topOrder[i];
//			printf("%c ", G.vertices[idx].vName);
//		}
//	}
//}

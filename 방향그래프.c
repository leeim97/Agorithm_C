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
//typedef struct Edge {			//���� ���
//	int orgIdx;					//���� ���� �ε���
//	int desIdx;					//���� ���� �ε���
//}edge;
//
//
//
//typedef struct IncidentEdge {	//��������Ʈ ���
//	int edgeIdx;				//�������� �ε���
//	struct IncidentEdge* next;
//}incidentEdge;
//
//
//typedef struct Vertex {			//���� ���
//	char vName;					//���� �̸�
//	int inDegree;				//���� ����
//	incidentEdge* InIEdges;		//���� ��������Ʈ(���Ḯ��Ʈ)
//	incidentEdge* OutIEdges;	//���� ��������Ʈ(���Ḯ��Ʈ)
//}vertex;
//
//typedef struct Graph {
//	vertex* vertices;			//���� ����Ʈ(�迭)
//	edge* edges;				//���� ����Ʈ(�迭)
//}graph;
//
//typedef struct Node {			//ť ���
//	int vIdx;					//���� �ε���
//	struct Node* next;
//}node;
//
//typedef struct Queue {
//	node* front;				//ť ���� ����
//	node* rear;					//ť ���� ����
//}queue;
//
////���� ����
//graph G;						//���� �׷���							
//int n, m;						//����, ���� ��
//int topOrder[NUMV_MAX + 1];		//DAG����[0], �������[1:n]
//queue Q;						//���� ���� ť
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
//// �׷��� ���� ����Ʈ(�迭)�� vIdx ��ġ�� vName�� ���ο� vertex ����
//void insertVertex(char vName, int vIdx) {
//	vertex p=getVertex();
//	p.vName = vName;
//
//	G.vertices[vIdx] = p;
//
//}
//
//// �׷��� ���� ����Ʈ(�迭)���� vName�� �ش��ϴ� ������ �ε����� ��ȯ
//int index(char vName) {
//	for (int i = 0; i < n; i++) {
//		if (G.vertices[i].vName == vName) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//// eIdx�� �����ϴ� ���ο� �������� ��带 vIdx ������ ��������Ʈ�� ���� �տ� ����
//// in_or_out == IN: ���� ��������Ʈ��. in_or_out == OUT: ���� ��������Ʈ�� ����
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
////�׷��� �ʱ�ȭ, ���� n�� �Է� ,���� m�� �Է�
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
//		G.edges[i].orgIdx = index(v1);	//���� ����
//		insertIncidentEdge(index(v1), i, OUT); //���� ��������Ʈ�� ������ v2
//		G.edges[i].desIdx = index(v2);	//���� ����
//		insertIncidentEdge(index(v2), i, IN);//���� ��������Ʈ�� ������ v1
//	}
//
//
//
//}
//
////ť�� ����ִ��� Ȯ��(front==NULL�̸� ť�� �������)
//int isEmpty() {
//	return Q.front == NULL;
//}
//
////���� �ε��� vIdx�� ť�� rear�� ����(ù ���Կ��� front���� ����)
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
////ť�� front���� ���� �ε��� ���� �� ��ȯ
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
////���� �ǻ��ڵ� �� ���� ���� ����
////in �迭(in[i]: ���� i�� ��������) ���, ���� ��ȣ ������ ��ü �������� ����,
////���� �����迭 topSort ������Ʈ
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
//		topOrder[i] = de;//��������� ������ �ε����� �ֱ�
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

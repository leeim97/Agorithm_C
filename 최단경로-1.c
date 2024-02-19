//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//
//#define NUMV_MAX 100+1		//�ִ� ���� ����
//#define INFTY 30000			//���Ѵ�( > �ִ밡��ġ * �ִ밣��)
//
//// ����: ���� ���� �迭�� 0���� �ʱ�ȭ��
//
//int graph[NUMV_MAX][NUMV_MAX];//[u][w] & [w][u]: ���� u,w �����ϴ� ������ ���� ����, ���� ������ 0
//int numVinPQ; //PQ ���� �ִ� ���� ��
//int isInPQ[NUMV_MAX]; //���� v: isInPQ[v]==1 �̸� PQ���� ����, PQ ���� ������ 0
//int d[NUMV_MAX]; //���� v:d[v]�� d(v) ����,���� INFTY�� �ʱ�ȭ
//int n, m,s; //�� ���� ��, ���� ��,���� ����
//
//
//
////n,m�� �Է¹ް�, ���� ���� �Է� �޾Ƽ� graph ������Ʈ
//void buildGraph() { // 13������ ���� ����
//	int v1, v2, w;
//	scanf("%d %d %d", &n, &m,&s);
//
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d %d", &v1, &v2, &w);
//		graph[v1][v2] = w;
//		graph[v2][v1] = w;
//		if (isInPQ[v1] == 0) {
//			isInPQ[v1] = 1;
//			numVinPQ++;
//		}
//		if (isInPQ[v2] == 0) {
//			isInPQ[v2] = 1;
//			numVinPQ++;
//		}
//	}
//}
//
////PQ ���� �ִ� ���� �� �ּ� d(v) ���� ��ȣ ��ȯ
//int findMinDvVertexInPQ() { //13������ ����
//	int cnt = 0;
//	int min=d[0];//d(v)�� �ּڰ�
//	int u=0; //d(v)�� �ּڰ��� ���� ����
//
//	for (int i = 0; i < NUMV_MAX; i++) {
//		if (isInPQ[i] == 1) {
//			if (min > d[i]) {
//				min=d[i];
//				u = i;
//			}
//			cnt++;
//		}
//		if (cnt == numVinPQ)
//			break;
//	}
//
//	return u;
//}
//
//// �������� d(v) ������Ʈ
//void DijkstraShortestPaths() {
//	int  u,z;
//	for (int i = 0; i < NUMV_MAX; i++) {
//		d[i] = INFTY;
//	}
//	d[s] = 0;
//
//	while (numVinPQ != 0) {
//		//u=removeMin
//		u = findMinDvVertexInPQ();
//		isInPQ[u] = 0;
//		numVinPQ--;
//
//		for (int i = 0; i < NUMV_MAX; i++) {
//			if (graph[u][i] != 0) {
//				z = i;
//				if (isInPQ[z] && d[u] + graph[u][z] < d[z]) {
//					d[z] = d[u] + graph[u][z];
//				}
//			}
//		}
//
//	}
//
//
//}
//
//// �ִܰŸ� ���
//void printDistances() {
//	for (int i = 0; i < NUMV_MAX; i++) {
//		if (d[i] != INFTY && i!=s)
//			printf("%d %d\n", i, d[i]);
//	}
//}
//
//int main() {
//	
//
//	buildGraph();
//	DijkstraShortestPaths();
//	printDistances();
//}

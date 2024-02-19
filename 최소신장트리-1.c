//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define NUMV_MAX 100+1 // �ִ� ���� ����
//#define INFTY 10000		// ���Ѵ�
//
//// ����: ���� ���� �迭�� 0���� �ʱ�ȭ��
//
//int graph[NUMV_MAX][NUMV_MAX];//[u][w] & [w][u]: ���� u,w �����ϴ� ������ ���� ����, ���� ������ 0
//int numVinPQ; //PQ ���� �ִ� ���� ��
//int isInPQ[NUMV_MAX]; //���� v: isInPQ[v]==1 �̸� PQ���� ����, PQ ���� ������ 0
//int d[NUMV_MAX]; //���� v:d[v]�� d(v) ����,���� PrimJarnikMST() ������ INFTY�� �ʱ�ȭ
//int p[NUMV_MAX]; //���� v:p[v]�� p(v) ���� (�θ� ���� ���� ��� �θ� ���� ��ȣ ����),���� -1�� �ʱ�ȭ
//int n, m; //�� ���� ��, ���� ��
//
////n,m�� �Է¹ް�, ���� ���� �Է� �޾Ƽ� graph ������Ʈ
//void buildGraph() {
//	int v1, v2, w;
//	scanf("%d %d", &n, &m);
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
//int findMinDvVertexInPQ() {
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
////Q.isEmpty()�� numVinPQ �̿�
////Q.removeMin()�� findMinDvVertexInPQ(), isInPQ,numVinPQ �̿�
////�� ���� ����� p,graph �̿�
//void PrimJarnikMST() {
//	int cnt = 0;
//	int s;
//	for (int i = 0; i < NUMV_MAX; i++) {
//		d[i] = INFTY;
//		p[i] = -1;
//	}
//	//���� ���� s ã��
//	for (int i = 0; i < NUMV_MAX; i++) {
//		if (isInPQ[i] == 1) {
//			s = i;
//			break;
//		}
//	}
//	d[s] = 0;
//	
//	//�켱���� ť���� buildgraph���� �̹� �־���
//	
//	
//	while (numVinPQ != 0) {
//		int z;
//		//Q.remove
//		int u = findMinDvVertexInPQ();
//		printf(" %d", u);	//mst ������ �߰��Ǵ� ����
//		isInPQ[u] = 0;
//		numVinPQ--;
//
//		for (int i = 0; i < NUMV_MAX; i++) {
//			if (graph[u][i] != 0) {
//				z = i;
//				if (isInPQ[z] && graph[u][z] < d[z]) {
//					d[z] = graph[u][z];
//					p[z] = u;
//				}
//			}
//
//		}
//
//
//	}
//
//}
//
//int main() {
//	int total=0;
//
//	buildGraph();
//	PrimJarnikMST();
//	for (int i = 0; i < NUMV_MAX; i++) {
//		if (p[i] != -1) {
//			total += graph[i][p[i]];
//		}
//	}
//
//
//	printf("\n%d", total);
//}

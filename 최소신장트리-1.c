//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define NUMV_MAX 100+1 // 최대 정점 개수
//#define INFTY 10000		// 무한대
//
//// 참고: 전역 변수 배열은 0으로 초기화됌
//
//int graph[NUMV_MAX][NUMV_MAX];//[u][w] & [w][u]: 정점 u,w 연결하는 간선의 무게 저장, 간선 없으면 0
//int numVinPQ; //PQ 내에 있는 정점 수
//int isInPQ[NUMV_MAX]; //정점 v: isInPQ[v]==1 이면 PQ내에 존재, PQ 내에 없으면 0
//int d[NUMV_MAX]; //정점 v:d[v]는 d(v) 저장,추후 PrimJarnikMST() 내에서 INFTY로 초기화
//int p[NUMV_MAX]; //정점 v:p[v]는 p(v) 저장 (부모를 향한 간선 대신 부모 정점 번호 저장),추후 -1로 초기화
//int n, m; //총 정점 수, 간선 수
//
////n,m을 입력받고, 간선 정보 입력 받아서 graph 업데이트
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
////PQ 내에 있는 정점 중 최소 d(v) 정점 번호 반환
//int findMinDvVertexInPQ() {
//	int cnt = 0;
//	int min=d[0];//d(v)의 최솟값
//	int u=0; //d(v)의 최솟값을 갖는 정점
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
////Q.isEmpty()는 numVinPQ 이용
////Q.removeMin()은 findMinDvVertexInPQ(), isInPQ,numVinPQ 이용
////총 무게 계산은 p,graph 이용
//void PrimJarnikMST() {
//	int cnt = 0;
//	int s;
//	for (int i = 0; i < NUMV_MAX; i++) {
//		d[i] = INFTY;
//		p[i] = -1;
//	}
//	//시작 정점 s 찾기
//	for (int i = 0; i < NUMV_MAX; i++) {
//		if (isInPQ[i] == 1) {
//			s = i;
//			break;
//		}
//	}
//	d[s] = 0;
//	
//	//우선순위 큐에는 buildgraph에서 이미 넣었음
//	
//	
//	while (numVinPQ != 0) {
//		int z;
//		//Q.remove
//		int u = findMinDvVertexInPQ();
//		printf(" %d", u);	//mst 생성시 추가되는 정점
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

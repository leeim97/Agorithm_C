//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//
//#define NUMV_MAX 100+1		//최대 정점 개수
//#define INFTY 30000			//무한대( > 최대가중치 * 최대간선)
//
//// 참고: 전역 변수 배열은 0으로 초기화됌
//
//int graph[NUMV_MAX][NUMV_MAX];//[u][w] & [w][u]: 정점 u,w 연결하는 간선의 무게 저장, 간선 없으면 0
//int numVinPQ; //PQ 내에 있는 정점 수
//int isInPQ[NUMV_MAX]; //정점 v: isInPQ[v]==1 이면 PQ내에 존재, PQ 내에 없으면 0
//int d[NUMV_MAX]; //정점 v:d[v]는 d(v) 저장,추후 INFTY로 초기화
//int n, m,s; //총 정점 수, 간선 수,시작 정점
//
//
//
////n,m을 입력받고, 간선 정보 입력 받아서 graph 업데이트
//void buildGraph() { // 13주차와 거의 동일
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
////PQ 내에 있는 정점 중 최소 d(v) 정점 번호 반환
//int findMinDvVertexInPQ() { //13주차와 동일
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
//// 정점들의 d(v) 업데이트
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
//// 최단거리 출력
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

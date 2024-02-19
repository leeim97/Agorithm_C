//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define NUMV_MAX 100+1  // 최대 정점 개수
//#define NUME_MAX 1000+1 // 최대 간선 개수
//#define INFTY 10000		// 무한대
//
//// 참고:전역변수는 0으로 초기화됨
//
//int vGroupNum[NUMV_MAX]; // 정점 v: vGroupNum[v]는 정점 v의 집합 번호 저장, 아직 집합 배정 안됐으면 0
//int edges[NUME_MAX][3];  // 간선 e: [e][0]: 정점1, [e][1]: 정점2, [e][2]: 무게
//int n, m;			     // 총 정점 수,간선 수
//
////n,m 입력받고, 간선 정보 입력받아서 edges 업데이트
//void buildGraph() {
//	int v1, v2, w;
//
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < m; i++) {
//
//		scanf("%d %d %d", &v1, &v2, &w);
//		edges[i][0] = v1;
//		edges[i][1] = v2;
//		edges[i][2] = w;
//
//	}
//
//}
//
//void KruskalMST() {
//	/*
//		edges를 무게를 기준으로 오름차순으로 정렬
//		최소 무게 간선의 양쪽 정점에 대해서,
//		-양쪽 정점 모두 집합 배정이 안 된 경우:두 정점을 같은 새로운 집합에 배정
//		-한쪽 정정만 집합에 배정된 경우: 배정되지 않은 정점을 나머지 정점의 집합에 배정
//		-양쪽 정점이 다른 집합에 배정되어 있는 경우: 한쪽 집합의 정점을 모두 나모지 집합에 배정
//
//	*/
//
//	//edges를 오름차순으로 정렬
//	for (int i = 0; i < m - 1; i++) {
//		int mine = i;
//		int minw = edges[i][2];
//		for (int j = i + 1; j < m; j++) {
//			if (minw > edges[j][2]) {
//				minw = edges[j][2];
//				mine = j;
//			}
//		}
//		int tempv1, tempv2, tempw;
//		tempv1 = edges[mine][0];
//		tempv2 = edges[mine][1];
//		tempw = edges[mine][2];
//
//
//		edges[mine][0] = edges[i][0];
//		edges[mine][1] = edges[i][1];
//		edges[mine][2] = edges[i][2];
//
//		edges[i][0] = tempv1;
//		edges[i][1] = tempv2;
//		edges[i][2] = tempw;
//	}
//
//
//	int v1 = 0, v2 = 0, w = 0, total = 0,temp1,temp2;
//
//	for (int i = 0; i < m; i++) {
//		v1 = edges[i][0];
//		v2 = edges[i][1];
//		w = edges[i][2];
//
//		//양쪽 배정 안된경우
//		if (vGroupNum[v1] == 0 && vGroupNum[v2] == 0) {
//			vGroupNum[v1] = v1;
//			vGroupNum[v2] = v1;
//			printf(" %d", w);
//			total += w;
//		}
//		//한쪽만 배정된 경우
//		else if (vGroupNum[v1] != 0 && vGroupNum[v2] == 0) {
//			vGroupNum[v2] = vGroupNum[v1];
//			printf(" %d", w);
//			total += w;
//		}
//		else if (vGroupNum[v1] == 0 && vGroupNum[v2] != 0) {
//			vGroupNum[v1] = vGroupNum[v2];
//			printf(" %d", w);
//			total += w;
//		}
//		//둘다 배정 된경우 한쪽 집합을 나머지 집합에 다 넣는다.
//		else if (vGroupNum[v1] != 0 && vGroupNum[v2] != 0) {
//			if (vGroupNum[v1] != vGroupNum[v2]) {
//				temp1 = vGroupNum[v1];
//				temp2 = vGroupNum[v2];
//
//				for (int j = 0; j < m; j++) {
//					//printf("vGroupNum[j]:%d\n", vGroupNum[j]);
//				
//					if (vGroupNum[j] == temp2) {
//						vGroupNum[j] = temp1;
//						//printf("넣을 집합:%d\n", vGroupNum[j]);
//						//printf("넣게될 집합:%d\n", vGroupNum[v1]);
//					}
//				}
//				printf(" %d", w);
//				total += w;
//			}
//		}
//	}
//	printf("\n%d", total);
//
//
//}
//
//int main() {
//
//	buildGraph();
//	KruskalMST();
//
//}

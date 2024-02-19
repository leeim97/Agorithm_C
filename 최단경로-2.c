# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define min(a,b) (((a)<(b))? (a):(b))

#define NUMV_MAX 100+1  // 최대 정점 개수
#define NUME_MAX 1000+1 // 최대 간선 개수
#define INFTY 30000		// 무한대(> 최대가중치* 최대간선수)

// 참고:전역변수는 0으로 초기화됨

int d[NUMV_MAX]; //정점 v:d[v]는 d(v) 저장,추후 벨만포드 내에서 INFTY로 초기화
int edges[NUME_MAX][3];  // 간선 e: [e][0]: 시점, [e][1]: 종점2, [e][2]: 무게
int n, m, s;			     // 총 정점 수,간선 수

//n,m 입력받고, 간선 정보 입력받아서 edges 업데이트
void buildGraph() {
	int v1, v2, w;

	scanf("%d %d %d", &n, &m, &s);

	for (int i = 0; i < m; i++) {

		scanf("%d %d %d", &v1, &v2, &w);
		edges[i][0] = v1;
		edges[i][1] = v2;
		edges[i][2] = w;

	}

}


void BellmanFordShortestPaths() {
	//초기화
	for (int i = 0; i < NUMV_MAX; i++) {
		d[i] = INFTY;
	}
	d[s] = 0;

	int u, z, w; //u는 시점, z는 종점 w는 두 정점사이의 가중치
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < m; j++) {
			u = edges[j][0];
			z = edges[j][1];
			w = edges[j][2];
			d[z] = min(d[u] + w, d[z]);
		}
	}
}

void printDistance() {
	for (int i = 0; i < NUMV_MAX; i++) {
//음의 가중치가 더해지면 INFTY가아니라 예를들어 29998이러니까 
// d[i]!=INFTY가 아니라
//최대가중치 20을뺀 29980보다 작아야한다		
		if ( d[i]<INFTY-20   && i != s) { 
			printf("%d %d\n", i, d[i]);
		}
	}
}

int main() {

	buildGraph();
	BellmanFordShortestPaths();
	printDistance();

}

# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define min(a,b) (((a)<(b))? (a):(b))

#define NUMV_MAX 100+1  // �ִ� ���� ����
#define NUME_MAX 1000+1 // �ִ� ���� ����
#define INFTY 30000		// ���Ѵ�(> �ִ밡��ġ* �ִ밣����)

// ����:���������� 0���� �ʱ�ȭ��

int d[NUMV_MAX]; //���� v:d[v]�� d(v) ����,���� �������� ������ INFTY�� �ʱ�ȭ
int edges[NUME_MAX][3];  // ���� e: [e][0]: ����, [e][1]: ����2, [e][2]: ����
int n, m, s;			     // �� ���� ��,���� ��

//n,m �Է¹ް�, ���� ���� �Է¹޾Ƽ� edges ������Ʈ
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
	//�ʱ�ȭ
	for (int i = 0; i < NUMV_MAX; i++) {
		d[i] = INFTY;
	}
	d[s] = 0;

	int u, z, w; //u�� ����, z�� ���� w�� �� ���������� ����ġ
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
//���� ����ġ�� �������� INFTY���ƴ϶� ������� 29998�̷��ϱ� 
// d[i]!=INFTY�� �ƴ϶�
//�ִ밡��ġ 20���� 29980���� �۾ƾ��Ѵ�		
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

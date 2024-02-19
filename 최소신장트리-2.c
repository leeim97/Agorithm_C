//# include<stdio.h>
//#include<stdlib.h>
//#include<string.h> 
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//#define NUMV_MAX 100+1  // �ִ� ���� ����
//#define NUME_MAX 1000+1 // �ִ� ���� ����
//#define INFTY 10000		// ���Ѵ�
//
//// ����:���������� 0���� �ʱ�ȭ��
//
//int vGroupNum[NUMV_MAX]; // ���� v: vGroupNum[v]�� ���� v�� ���� ��ȣ ����, ���� ���� ���� �ȵ����� 0
//int edges[NUME_MAX][3];  // ���� e: [e][0]: ����1, [e][1]: ����2, [e][2]: ����
//int n, m;			     // �� ���� ��,���� ��
//
////n,m �Է¹ް�, ���� ���� �Է¹޾Ƽ� edges ������Ʈ
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
//		edges�� ���Ը� �������� ������������ ����
//		�ּ� ���� ������ ���� ������ ���ؼ�,
//		-���� ���� ��� ���� ������ �� �� ���:�� ������ ���� ���ο� ���տ� ����
//		-���� ������ ���տ� ������ ���: �������� ���� ������ ������ ������ ���տ� ����
//		-���� ������ �ٸ� ���տ� �����Ǿ� �ִ� ���: ���� ������ ������ ��� ������ ���տ� ����
//
//	*/
//
//	//edges�� ������������ ����
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
//		//���� ���� �ȵȰ��
//		if (vGroupNum[v1] == 0 && vGroupNum[v2] == 0) {
//			vGroupNum[v1] = v1;
//			vGroupNum[v2] = v1;
//			printf(" %d", w);
//			total += w;
//		}
//		//���ʸ� ������ ���
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
//		//�Ѵ� ���� �Ȱ�� ���� ������ ������ ���տ� �� �ִ´�.
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
//						//printf("���� ����:%d\n", vGroupNum[j]);
//						//printf("�ְԵ� ����:%d\n", vGroupNum[v1]);
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

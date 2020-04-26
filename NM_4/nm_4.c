#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void backTrack(int n);

int N, M;
int list[8];
int visited[9] = { 0, };
int asc;

int main() {
	scanf("%d %d", &N, &M);
	backTrack(0);

	return 0;
}

void backTrack(int n) {

	//���̰� ������ list ���
	if (n == M) {

		//�񳻸������� �ƴϸ� asc ���
		asc = 0;
		for (int i = 0; i < M - 1; i++) {
			if (list[i] > list[i + 1])
				asc++;
		}

		//�񳻸������� ��� list ���
		if (asc > 0) {
		}
		else {
			for (int i = 0; i < M; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
	}

	//������ �ߺ��� ����ϱ� ������ visit�� +�ؼ� ������ ���� ��ŭ ���� ����
	for (int k = 1; k <= N; k++) {
		if (visited[k] < M && n != M) {
			visited[k]++;
			list[n] = k;
			backTrack(n + 1);
			visited[k]--; //��͹��� �����鼭 �������������� visit�� �ʱ�ȭ
		}
	}
}
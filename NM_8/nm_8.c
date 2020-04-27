#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int num_list[9];
int list[8];
int visited[9] = { 0, };
int asc;

void backTrack(int n);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &num_list[i]);
	}

	//�������� ����
	for (int i = 1; i < N + 1; i++) {
		for (int k = 1; k < N; k++) {
			if (num_list[k] > num_list[k + 1]) {
				int temp;
				temp = num_list[k];
				num_list[k] = num_list[k + 1];
				num_list[k + 1] = temp;
			}
		}
	}

	backTrack(0);

	return 0;
}

void backTrack(int n)
{
	//���̰� ������ ���� ���
	if (n == M) {

		//�񳻸������� �ƴ� ��� asc ���
		asc = 0;
		for (int i = 0; i < M - 1; i++) {
			if (list[i] > list[i + 1])
				asc++;
		}

		//�񳻸������� ��츸 list ���
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
			list[n] = num_list[k];
			backTrack(n + 1);
			visited[k]--; //��͹� �����鼭 ���������� ���� visited �ʱ�ȭ
		}
	}
}

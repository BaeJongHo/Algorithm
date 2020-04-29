#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int num_list[8];
int list[8];
int asc;

void backTrack(int n, int index);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num_list[i]);
	}

	//�������� ����
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N - 1; k++) {
			if (num_list[k] > num_list[k + 1]) {
				int temp;
				temp = num_list[k];
				num_list[k] = num_list[k + 1];
				num_list[k + 1] = temp;
			}
		}
	}

	backTrack(0, 0);

	return 0;
}

void backTrack(int n, int index) {

	//������ ���̿� ���������� ���
	if (n == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	//�ߺ��� Ȯ��
	int prev_num[10000] = { 0 };

	for (int k = index; k < N; k++) {
		//�湮���� �ʾҴ� ���̸� list�� insert
		if (prev_num[num_list[k]] == 0) {
			prev_num[num_list[k]] = 1;
			list[n] = num_list[k];
			backTrack(n + 1, k);
		}
	}
}
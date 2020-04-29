#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int num_list[8];
int list[8];

void backTrack(int n);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num_list[i]);
	}

	//오름차순 정렬
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

void backTrack(int n) {

	//수열의 길이에 도달했을때 출력
	if (n == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	//중복값 확인
	int prev_num = -1;

	for (int k = 1; k <= N; k++) {
		//방문하지 않았던 수이면 list에 insert
		if (prev_num != num_list[k]) {
			list[n] = num_list[k];
			prev_num = num_list[k];
			backTrack(n + 1);
		}
	}
}
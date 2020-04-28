#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int N, M;
int num_list[9];
int list[8];
int asc;
bool visited[9] = { false, };

void backTrack(int n);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
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

		//수열이 비내림차순이 아닌 경우 asc 양수
		asc = 0;
		for (int i = 0; i < M - 1; i++) {
			if (list[i] > list[i + 1])
				asc++;
		}

		//비내림차순인 경우만 출력
		if (asc > 0) {
		}
		else {
			for (int i = 0; i < M; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
	}

	//중복값 확인
	int prev[10001] = { 0 };

	for (int k = 1; k <= N; k++) {
		//방문하지 않았던 수이면 list에 insert
		if (!visited[k] && prev[num_list[k]] == 0) {
			prev[num_list[k]] = 1;
			visited[k] = true;
			list[n] = num_list[k];
			backTrack(n + 1);
			visited[k] = false; //재귀문 나오면서 마지막에서 부터 visited 초기화
		}
	}
}
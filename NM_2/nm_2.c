#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void backTrack(int n);

int N, M;
int list[8];
int prev_list[8];
int check;
int asc;
bool visited[9] = { false, };

int main() {
	scanf("%d %d", &N, &M);
	backTrack(0);

	return 0;
}

void backTrack(int n) {

	if (n == M) {

		//오름차순 정렬이 아닌 경우 asc 양수
		asc = 0;
		for (int j = 0; j < M - 1; j++) {
			if (list[j] > list[j + 1])
				asc++;
		}

		//오름차순 정렬이 아닌 경우 출력 방지
		if (asc > 0) {
		}
		else {

			//전과 동일한 수열 출력 방지
			check = 0;
			for (int i = 0; i < M; i++) {
				if (prev_list[i] == list[i])
					check++;
			}

			//동일한 수열이 아니면 출력
			if (check == M) {
			}
			else {
				for (int i = 0; i < M; i++) {
					prev_list[i] = list[i];
					printf("%d ", list[i]);
				}
				printf("\n");
			}
		}
	}

	for (int k = 1; k <= N; k++) {
		if (!visited[k]) {
			visited[k] = true;
			list[n] = k;
			backTrack(n + 1);
			visited[k] = false;
		}
	}
}
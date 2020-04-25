#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void backTrack(int n);

int N, M;
int list[8];
bool visited[9] = {false,};

int main() {
	scanf("%d %d", &N, &M);
	backTrack(0);

	return 0;
}

void backTrack(int n) {

	if (n == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void backTrack(int n);

int N, M;
int list[8];
int visited[9] = { 0, };

int main() {
	scanf("%d %d", &N, &M);
	backTrack(0);

	return 0;
}

void backTrack(int n) {

	//길이가 같을때 list 출력
	if (n == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	}

	//수열이 중복을 허용하기 때문에 visit을 +해서 수열의 길이 만큼 고르게 해줌
	for (int k = 1; k <= N; k++) {
		if (visited[k] < M && n != M) {
			visited[k]++;
			list[n] = k;
			backTrack(n + 1);
			visited[k]--; //재귀문을 나오면서 마지막에서부터 visit을 초기화
		}
	}
}
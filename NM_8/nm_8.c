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

void backTrack(int n)
{
	//길이가 같을때 수열 출력
	if (n == M) {

		//비내림차순이 아닌 경우 asc 양수
		asc = 0;
		for (int i = 0; i < M - 1; i++) {
			if (list[i] > list[i + 1])
				asc++;
		}

		//비내림차순인 경우만 list 출력
		if (asc > 0) {
		}
		else {
			for (int i = 0; i < M; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
	}

	//수열이 중복을 허용하기 때문에 visit을 +해서 수열의 길이 만큼 고르게 해줌
	for (int k = 1; k <= N; k++) {
		if (visited[k] < M && n != M) {
			visited[k]++;
			list[n] = num_list[k];
			backTrack(n + 1);
			visited[k]--; //재귀문 나오면서 마지막에서 부터 visited 초기화
		}
	}
}

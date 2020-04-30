#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int* arr;
int* visited;
int* list;
int next = 0;

void dfs(int n);

int main()
{
	int check = 0;

	scanf("%d", &N);

	visited = new int[N + 1];

	for (int i = 0; i < N + 1; i++) {
		visited[i] = 0;
	}


	list = new int[N];

	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		if (arr[i] > arr[i + 1])
			check++;
	}

	if (check == N - 1)
		printf("-1");
	else {
		dfs(0);
	}
}

void dfs(int n) {
	if (n == N) {
		if (next == 1) {
			for (int i = 0; i < N; i++)
				printf("%d ", list[i]);
			exit(0);
		}
		
		int check = 0;

		for (int i = 0; i < N; i++) {
			if (list[i] == arr[i])
				check++;
		}

		if (check == N)
			next = 1;

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			list[n] = i;
			dfs(n + 1);
			visited[i] = 0;
		}
	}
}
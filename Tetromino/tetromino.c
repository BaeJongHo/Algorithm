#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = 0;
int** board;
int N, M;

void shape1();
void shape2();
void shape3();
void shape4();
void shape5();

int main() {

	scanf("%d", &N);
	scanf("%d", &M);

	board = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(sizeof(int) * M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	shape1();
	shape2();
	/*
	shape3();
	shape4();
	shape5();
	*/
	printf("%d", max);
}

void shape1() {
	for (int i = 0; i < N; i++) {
		int result = 0;
		for (int j = 0; j < M - 4; j++) {
			result = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (result > max)
				max = result;
		}
	}

	for (int i = 0; i < N; i++) {
		int result = 0;
		for (int j = 0; j < M - 4; j++) {
			result = board[j][i] + board[j + 1][i] + board[j + 2][i] + board[j + 3][i];
			if (result > max)
				max = result;
		}
	}
}

void shape2() {
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
			if (result > max)
				max = result;
		}
	}
}
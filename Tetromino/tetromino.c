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
	shape3();
	shape4();
	shape5();
	
	printf("%d", max);
	return 0;
}

void shape1() {

	//0000
	for (int i = 0; i < N; i++) {
		int result = 0;
		for (int j = 0; j < M - 3; j++) {
			result = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (result > max)
				max = result;
		}
	}

	//0
	//0
	//0
	//0
	for (int i = 0; i < N - 3; i++) {
		int result = 0;
		for (int j = 0; j < M; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (result > max)
				max = result;
		}
	}
}

void shape2() {

	//00
	//00
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
			if (result > max)
				max = result;
		}
	}
}

void shape3() {

	//0
	//0
	//00
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
			if (result > max)
				max = result;
		}
	}

	//00
	//0
	//0
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
			if (result > max)
				max = result;
		}
	}

	//000
	//0
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
			if (result > max)
				max = result;
		}
	}

	//000
	//  0
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
			if (result > max)
				max = result;
		}
	}

	// 0
	// 0
	//00
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i + 2][j] + board[i + 2][j + 1] + board[i + 1][j + 1] + board[i][j + 1];
			if (result > max)
				max = result;
		}
	}

	//00
	// 0
	// 0
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (result > max)
				max = result;
		}
	}

	//  0
	//000
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
			if (result > max)
				max = result;
		}
	}

	//0
	//000
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (result > max)
				max = result;
		}
	}
}

void shape4() {

	//0
	//00
	// 0
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (result > max)
				max = result;
		}
	}

	// 0
	//00
	//0
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j];
			if (result > max)
				max = result;
		}
	}

	//00
	// 00
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (result > max)
				max = result;
		}
	}

	// 00
	//00
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2];
			if (result > max)
				max = result;
		}
	}
}

void shape5() {
	
	//で
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 1];
			if (result > max)
				max = result;
		}
	}

	//ぬ
	for (int i = 0; i < N - 1; i++) {
		int result = 0;
		for (int j = 0; j < M - 2; j++) {
			result = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
			if (result > max)
				max = result;
		}
	}

	//っ
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 1][j];
			if (result > max)
				max = result;
		}
	}

	//た
	for (int i = 0; i < N - 2; i++) {
		int result = 0;
		for (int j = 0; j < M - 1; j++) {
			result = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
			if (result > max)
				max = result;
		}
	}
}
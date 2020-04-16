#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, count;
char** board;
int max = 0;

//두 char 값을 스왑하는 함수
void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//붙어 있는 사탕의 개수 세는 함수
void counting()
{
	//가로의 사탕 개수 세기
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N - 1; j++) {
			//붙어 있는 사탕이 같으면 count + 1, 아니면 count 초기화
			if (board[i][j] == board[i][j + 1]) {
				count++;
			}
			else {
				//붙어 있는 사탕이 다른 경우, max와 count 중 큰 값으로 max 초기화 후 count 초기화
				if (max < count)
					max = count;
				count = 1;
			}
		}
		//한줄에 같은 사탕만 있는 경우 max가 초기화되지 않기 때문에 max 초기화를 해줘야함
		if (max < count)
			max = count;
	}

	//세로의 사탕 개수 세기
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N - 1; j++) {
			//붙어 있는 사탕이 같으면 count + 1, 아니면 count 초기화
			if (board[j][i] == board[j + 1][i]) {
				count++;
			}
			else {
				//붙어 있는 사탕이 다른 경우, max와 count 중 큰 값으로 max 초기화 후 count 초기화
				if (max < count)
					max = count;
				count = 1;
			}
		}
		//한줄에 같은 사탕만 있는 경우 max가 초기화되지 않기 때문에 max 초기화를 해줘야함
		if (max < count)
			max = count;
	}
}

int main() {

	//N입력
	while (1) {
		scanf("%d", &N);
		if (N < 3) {
			printf("N을 다시 입력하시오\n");
		}
		else if (N > 50) {
			printf("N을 다시 입력하시오\n");
		}
		else {
			break;
		}
	}

	//이중배열 동적할당
	board = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		board[i] = (char*)malloc(sizeof(char) * N);
	}

	//입력받기
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < N; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	//가로 개수 세기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(&board[i][j], &board[i][j + 1]);
			counting();
			swap(&board[i][j], &board[i][j + 1]);
		}
	}

	//세로 개수 세기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(&board[j][i], &board[j + 1][i]);
			counting();
			swap(&board[j][i], &board[j + 1][i]);
		}
	}

	printf("%d", max);
	return 0;
}
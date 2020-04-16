#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, count;
char** board;
int max = 0;

//�� char ���� �����ϴ� �Լ�
void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//�پ� �ִ� ������ ���� ���� �Լ�
void counting()
{
	//������ ���� ���� ����
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N - 1; j++) {
			//�پ� �ִ� ������ ������ count + 1, �ƴϸ� count �ʱ�ȭ
			if (board[i][j] == board[i][j + 1]) {
				count++;
			}
			else {
				//�پ� �ִ� ������ �ٸ� ���, max�� count �� ū ������ max �ʱ�ȭ �� count �ʱ�ȭ
				if (max < count)
					max = count;
				count = 1;
			}
		}
		//���ٿ� ���� ������ �ִ� ��� max�� �ʱ�ȭ���� �ʱ� ������ max �ʱ�ȭ�� �������
		if (max < count)
			max = count;
	}

	//������ ���� ���� ����
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N - 1; j++) {
			//�پ� �ִ� ������ ������ count + 1, �ƴϸ� count �ʱ�ȭ
			if (board[j][i] == board[j + 1][i]) {
				count++;
			}
			else {
				//�پ� �ִ� ������ �ٸ� ���, max�� count �� ū ������ max �ʱ�ȭ �� count �ʱ�ȭ
				if (max < count)
					max = count;
				count = 1;
			}
		}
		//���ٿ� ���� ������ �ִ� ��� max�� �ʱ�ȭ���� �ʱ� ������ max �ʱ�ȭ�� �������
		if (max < count)
			max = count;
	}
}

int main() {

	//N�Է�
	while (1) {
		scanf("%d", &N);
		if (N < 3) {
			printf("N�� �ٽ� �Է��Ͻÿ�\n");
		}
		else if (N > 50) {
			printf("N�� �ٽ� �Է��Ͻÿ�\n");
		}
		else {
			break;
		}
	}

	//���߹迭 �����Ҵ�
	board = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		board[i] = (char*)malloc(sizeof(char) * N);
	}

	//�Է¹ޱ�
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < N; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	//���� ���� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(&board[i][j], &board[i][j + 1]);
			counting();
			swap(&board[i][j], &board[i][j + 1]);
		}
	}

	//���� ���� ����
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
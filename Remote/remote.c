#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min = 1000000;
int* btns;
int length;
int ten;
int chn;
int buttonNum;

int check(int);
int main() {
	scanf("%d", &chn);
	scanf("%d", &buttonNum);

	btns = (int *)malloc(sizeof(int) * buttonNum);

	for (int i = 0; i < buttonNum; i++) {
		scanf("%d", &btns[i]);
	}

	if (chn >= 100) {
		if (min > chn - 100)
			min = chn - 100;
	}
	else {
		if (min > 100 - chn)
			min = 100 - chn;
	}

	for (int i = 0; i < 1000001; i++) {
		
		length = 1;
		ten = 10;

		//번호의 자릿수 계산
		while (1) {
			if ((float)(i / ten) < 1)
				break;
			else
				length++;
			ten *= 10;
		}

		//누를 수 있는 번호면 그 번호에서부터 채널까지 가는 횟수 계산
		if (check(i)) {
			int s = chn - i;
			if (s < 0)
				s = s * -1;
			if (s + length < min) {
				min = s + length;
			}
		}
	}
	printf("%d", min);
}

//누를 수 있는 번호인지 확인
int check(int num) {
	if (num == 0) {
		for (int i = 0; i < buttonNum; i++) {
			if (btns[i] == 0)
				return 0;
		}
		return 1;
	}

	while (num) {
		for (int i = 0; i < buttonNum; i++) {
			if (num % 10 == btns[i])
				return 0;
		}
		num /= 10;
	}
	return 1;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min = 1000000;
int btns[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int length;

int check(int);
int main() {
	int chn;
	int buttonNum;

	scanf("%d", &chn);
	scanf("%d", &buttonNum);

	for (int i = 0; i < buttonNum; i++) {
		int k;
		scanf("%d", &k);
		btns[k] = 1;
	}

	if (chn >= 100) {
		if (min > chn - 100)
			min = chn - 100;
	}
	else {
		if (min > 100 - chn)
			min = 100 - chn;
	}

	for (int i = 0; i < 100001; i++) {
		int length = check(i);
		if (length) {
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

int check(int k) {
	length = 0;
	if (k == 0) {
		if (btns[0])
			return 1;
		else
			return 0;
	}
	while (k) {
		length++;
		if (btns[k % 10])
			return 0;
		k = k / 10;
	}
	return length;
}
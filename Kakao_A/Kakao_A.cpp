#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t, a, b;
	int* reward_list;
	int reward;

	scanf("%d", &t);
	reward_list = (int*)malloc(sizeof(int) * t);

	for (int i = 0; i < t; i++) {
		reward = 0;
		scanf("%d %d", &a, &b);
		if (a == 1)
			reward += 5000000;
		else if (a > 1 && a <= 3)
			reward += 3000000;
		else if (a > 3 && a <= 6)
			reward += 2000000;
		else if (a > 6 && a <= 10)
			reward += 500000;
		else if (a > 10 && a <= 15)
			reward += 300000;
		else if (a > 15 && a <= 21)
			reward += 100000;

		if (b == 1)
			reward += 5120000;
		else if (b > 1 && b <= 3)
			reward += 2560000;
		else if (b > 3 && b <= 7)
			reward += 1280000;
		else if (b > 7 && b <= 15)
			reward += 640000;
		else if (b > 15 && b <= 31)
			reward += 320000;

		reward_list[i] = reward;
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n", reward_list[i]);
	}

	return 0;
}
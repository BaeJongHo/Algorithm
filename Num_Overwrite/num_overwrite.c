#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num;
int digit = 0;

int main() {
	int i = 1;

	scanf("%d", &num);
	
	while (1) {
		if (i < 10)
			digit += 1;
		
		if (i >= 10 && i < 100)
			digit += 2;

		if (i >= 100 && i < 1000)
			digit += 3;

		if (i >= 1000 && i < 10000)
			digit += 4;

		if (i >= 10000 && i < 100000)
			digit += 5;

		if (i >= 100000 && i < 1000000)
			digit += 6;

		if (i >= 1000000 && i < 10000000)
			digit += 7;

		if (i >= 10000000 && i < 100000000)
			digit += 8;

		if (i == 100000000)
			digit += 9;

		if (i == num)
			break;

		i++;
	}

	printf("%d", digit);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int E, S, M; //1~15, 1~28, 1~19
	int result;
	int year = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			result = year;
			break;
		}
		else
			year += 1;
	}
	printf("%d", result);
	return 0;
}
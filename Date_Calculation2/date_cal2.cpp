#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int E, S, M; //1~15, 1~28, 1~19
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if (E % 28 == S && E % 19 == M) {
			break;
		}
		else
			E += 15;
	}
	printf("%d", E);
	return 0;
}
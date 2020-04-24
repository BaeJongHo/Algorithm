#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int method_count(int n);

int main() {
	int count;
	int* arr;
	int method;

	scanf("%d", &count);

	arr = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < count; i++) {
		method = method_count(arr[i]);
		printf("%d\n", method);
	}

	return 0;
}

int method_count(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else
		return method_count(n - 1) + method_count(n - 2) + method_count(n - 3);
}
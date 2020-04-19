#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int M, N, x, y;
int** arr;
int T;

int calendar(int a[]);

int main() {
	int year;
	scanf("%d", &T);

	arr = (int**)malloc(sizeof(int*) * T);

	for (int i = 0; i < T; i++)
		arr[i] = (int*)malloc(sizeof(int) * 4);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}

	for (int i = 0; i < T; i++) {
		year = calendar(arr[i]);
		printf("%d\n", year);
	}
}

//날짜 계산
int calendar(int a[]) {
	int num = a[0];
	int lcm;
	int i = 1;
	int count;
	int max;
	int max_val;
	int min;
	int min_val;

	if (a[0] > a[1]) {
		min = a[1];
		min_val = a[3];
		max = a[0];
		max_val = a[2];
	}
	else if (a[0] == a[1]){
		min = a[0];
		min_val = a[2];
		max = a[1];
		max_val = a[3];
	}
	else if (a[0] < a[1]) {
		min = a[0];
		min_val = a[2];
		max = a[1];
		max_val = a[3];
	}

	while (1) {
		lcm = num * i;
		if (lcm % a[0] == 0 && lcm % a[1] == 0) {
			break;
		}
		i++;
	}

	i = 0;

	while (1) {
		count = i * max + max_val;

		if (lcm < count)
			return -1;
		
		if ((count - min_val) % min == 0) {
			return count;
		}
		i++;
	}
}
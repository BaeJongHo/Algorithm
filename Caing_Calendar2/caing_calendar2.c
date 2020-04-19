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
	int count = a[2];
	int lcm;
	int i = 1;

	//최소공배수 구하기
	while (1) {
		lcm = num * i;
		if (lcm % a[0] == 0 && lcm % a[1] == 0) {
			break;
		}
		i++;
	}

	while (1) {

		//최소공배수보다 커지면 -1 return
		if (lcm < count)
			return -1;

		//년도 return
		if ((count - a[3]) % a[1] == 0) {
			return count;
		}

		count += a[0];
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

int N, K;
int* arr;

int main()
{
	long double min = 1000000;
	long double stdv;
	long double avg, dev;
	long double k;

	scanf("%d %d", &N, &K);
	
	arr = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N - K + 1; i++) {
		k = K;
		while (i + k <= N) {
			avg = 0;
			dev = 0;

			for (int j = i; j < i + k; j++) {
				avg += arr[j];
			}
			avg /= k;

			for (int j = i; j < i + k; j++) {
				dev += pow(arr[j] - avg, 2);
			}
			dev /= k;

			stdv = sqrt(dev);

			if (min > stdv)
				min = stdv;

			k++;
		}
	}

	printf("%.10Lf", min);

	return 0;
}
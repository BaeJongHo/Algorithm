#include <iostream>

using namespace std;

int N, S;
int arr[20];
int result = 0;

void subset(int idx, int sum);

int main(void) {
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	subset(0, 0);

	cout << result;

	return 0;
}

void subset(int idx, int sum) {
	sum += arr[idx];

	if (idx >= N)
		return;

	if (sum == S)
		result++;

	subset(idx + 1, sum - arr[idx]);
	subset(idx + 1, sum);
}
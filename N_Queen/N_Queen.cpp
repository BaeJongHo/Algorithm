#include <iostream>

using namespace std;

int N;
int a1[20], a2[40], a3[40];

int dfs(int y);

int main()
{
	cin >> N;
	int result = dfs(0);

	cout << result;
}

int dfs(int y) {
	if (y == N)
		return 1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (a1[i] || a2[y + i] || a3[N - 1 + (y - i)])
			continue;
		a1[i] = a2[y + i] = a3[N - 1 + (y - i)] = 1;
		sum += dfs(y + 1);
		a1[i] = a2[y + i] = a3[N - 1 + (y - i)] = 0;
	}
	return sum;
}
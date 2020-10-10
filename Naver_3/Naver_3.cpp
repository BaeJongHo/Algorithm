#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
long long answer = 0;

void dfs(int n, int k);

int main()
{
	int k = 6;

	if (k == 6)
		answer += 1;

	dfs(0, k);

	cout << answer;

	return 0;
}

void dfs(int n, int k)
{
	if (n == k) {
		answer += 1;
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (n == 0 && i == 0)
			continue;

		int need = cnt[i];
		if (n + need <= k) {
			n += need;
			dfs(n, k);
			n -= need;
		}
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

int N, k;
long long calc(int n);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> k;

	if (calc(N) < k) {
		cout << -1;
		return 0;
	}

	int left = 1;
	int right = N;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (k > len) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);

	cout << s[s.size() - (l - k) - 1];

	return 0;
}

long long calc(int n) {
	long long ans = 0;

	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end >= n)
			ans += (long)((n - start + 1) * len);
		else
			ans += (long)((end - start + 1) * len);
	}

	return ans;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

long long ans = 0;
long long N, arr[27];
vector<long long> V;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> S;
		int cnt = 1;
		for (int j = S.size() - 1; j >= 0; j--) {
			arr[S[j] - 'A'] += cnt;
			cnt *= 10;
		}
	}
	
	for (int i = 0; i < 27; ++i)
		if (arr[i] != 0)
			V.push_back(arr[i]);

	sort(V.begin(), V.end());
	

	int value = 9;
	for (int i = V.size() - 1; i >= 0; i--) {
		ans += V[i] * value;
		value--;
	}

	cout << ans;

	return 0;
}
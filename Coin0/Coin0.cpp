#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;
int result = 0;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	while (K != 0) {
		int coin = v.back();
		v.pop_back();

		if (coin > K)
			continue;
		
		int cnt = K / coin;
		K -= (K / coin) * coin;
		result += cnt;
	}

	cout << result;

	return 0;
}
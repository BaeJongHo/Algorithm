#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	long long result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			result += v[j];
		}
	}

	cout << result;

	return 0;
}
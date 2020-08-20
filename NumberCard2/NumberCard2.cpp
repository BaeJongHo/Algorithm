#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a) << " ";
	}

	return 0;
}
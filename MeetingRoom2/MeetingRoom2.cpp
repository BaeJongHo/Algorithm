#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}

	sort(v.begin(), v.end());

	int pos_start = 0;
	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		int start = v[i].second;
		int end = v[i].first;

		if (pos_start <= start) {
			pos_start = end;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
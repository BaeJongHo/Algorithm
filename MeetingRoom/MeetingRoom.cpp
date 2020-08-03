#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> v;
int ans = 0;

void bfs(int last, int cnt);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	bfs(0, 0);

	cout << ans;

	return 0;
}

void bfs(int last, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(last, cnt));

	while (!q.empty()) {
		int pos_start = q.front().first;
		int num = q.front().second;

		q.pop();

		ans = max(ans, num);

		for (int i = 0; i < v.size(); i++) {
			int next = v[i].first;
			int end = v[i].second;

			if (next < pos_start)
				continue;

			q.push(make_pair(end, num + 1));
		}
	}
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int info[110];
bool visited[110];

void bfs(int idx);

int main()
{
	cin >> N >> M;

	memset(info, 0, sizeof(info));

	for (int i = 0; i < N + M; i++) {
		int x, y;
		cin >> x >> y;
		info[x] = y;
	}

	bfs(1);
}

void bfs(int idx) {
	queue<pair<int, int>> q;
	q.push(make_pair(idx, 0));
	visited[idx] = true;

	while (!q.empty()) {
		int loca = q.front().first;
		int cnt = q.front().second;

		if (loca == 100) {
			cout << cnt;
			break;
		}

		q.pop();

		for (int i = 6; i >= 1; i--) {
			int next = loca + i;
			if (next > 100 || visited[next])
				continue;

			if (info[next] != 0) {
				q.push(make_pair(info[next], cnt + 1));
				visited[next] = true;
			}
			else {
				q.push(make_pair(next, cnt + 1));
				visited[next] = true;
			}
		}
	}
}
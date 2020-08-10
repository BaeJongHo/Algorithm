#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[1000][1000];
int res_map[1000][1000] = { 0, };
int dX[] = { -1, 0, 1, 0 };
int dY[] = { 0, -1, 0, 1 };
bool visited[1000][1000] = { false, };
vector<pair<int, int>> v;

void dfs(int x, int y, int n);
void bfs(int x, int y);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - 48;
			if (map[i][j] == 1)
				v.push_back(make_pair(i, j));
		}
	}

	dfs(0, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << res_map[i][j];
		cout << "\n";
	}

	return 0;
}

void dfs(int x, int y, int n) {
	if (n == 1) {
		memset(visited, false, sizeof(visited));
		bfs(x, y);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		int curX = v[i].first;
		int curY = v[i].second;
		map[curX][curY] = 0;
		dfs(curX, curY, n + 1);
		map[curX][curY] = 1;
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 1;
	visited[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;

			if (map[nextX][nextY] == 1)
				continue;

			if (map[nextX][nextY] == 0 && !visited[nextX][nextY]) {
				cnt++;
				visited[nextX][nextY] = true;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
	res_map[x][y] = cnt;
}
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

char map[8][8];
const int dx[9] = { -1,0,1,1,1,0,-1,-1,0 };
const int dy[9] = { 1,1,1,0,-1,-1,-1,0,0 };
bool visited[9][8][8];

void bfs();

int main()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	bfs();

	return 0;
}

void bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0,7,0 });
	visited[0][7][0] = true;

	int ans = 0;
	while (!q.empty()) {
		int t, x, y;
		tie(t, x, y) = q.front();
		q.pop();

		if (x == 0 && y == 7)
			ans = 1;


		for (int i = 0; i < 9; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = min(t + 1, 8);

			if (!(0 <= nx && nx < 8 && 0 <= ny && ny < 8))
				continue;

			if (nx - t >= 0 && map[nx - t][ny] == '#')
				continue;

			if (nx - t - 1 >= 0 && map[nx - t - 1][ny] == '#')
				continue;

			if (!visited[nt][nx][ny]) {
				visited[nt][nx][ny] = true;
				q.push({ nt,nx,ny, });
			}

		}
	}
	if (ans) cout << 1;
	else cout << 0;
}
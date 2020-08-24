#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int R, C;
char map[50][50];
bool visited[50][50] = { false, };
queue<pair<int, int>> water;
queue<pair<int, int>> start;
int end_x, end_y;
int dX[4] = { 0, 0, -1, 1 };
int dY[4] = { -1, 1, 0 ,0 };

void bfs();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				start.push(make_pair(i, j));
				visited[i][j] = true;
			}
			else if (map[i][j] == 'D') {
				end_x = i; 
				end_y = j;
			}
			else if (map[i][j] == '*')
				water.push(make_pair(i, j));
		}
	}

	bfs();

	return 0;
}

void bfs() {
	int cnt = 0;
	while (!start.empty()) {
		cnt++;
		int water_size = water.size();
		while (water_size--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dX[i];
				int ny = y + dY[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == '*')
					continue;
				water.push(make_pair(nx, ny));
				map[nx][ny] = '*';
			}
		}

		int start_size = start.size();
		while (start_size--) {
			int x = start.front().first;
			int y = start.front().second;
			start.pop();

			if (x == end_x && y == end_y) {
				cout << cnt - 1;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dX[i];
				int ny = y + dY[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == '*' || visited[nx][ny])
					continue;
				start.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	cout << "KAKTUS";
}
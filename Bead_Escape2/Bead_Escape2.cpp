#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 11

int N, M;
char arr[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX] = { false };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
int red_x, red_y, blue_x, blue_y;

int bfs();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			else if (arr[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
		}
	}

	cout << bfs();

	return 0;
}

int bfs() {
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(red_x, red_y), make_pair(blue_x, blue_y)));
	visit[red_x][red_y][blue_x][blue_y] = true;
	int result = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int redball_x = q.front().first.first;
			int redball_y = q.front().first.second;
			int blueball_x = q.front().second.first;
			int blueball_y = q.front().second.second;

			q.pop();
			if (arr[redball_x][redball_y] == 'O' && arr[redball_x][redball_y] != arr[blueball_x][blueball_y]) {
				return result;
			}

			for (int i = 0; i < 4; i++) {
				int red_nx = redball_x, red_ny = redball_y, blue_nx = blueball_x, blue_ny = blueball_y;
				while (arr[red_nx + dx[i]][red_ny + dy[i]] != '#' && arr[red_nx][red_ny] != 'O') {
					red_nx += dx[i];
					red_ny += dy[i];
				}
				while (arr[blue_nx + dx[i]][blue_ny + dy[i]] != '#' && arr[blue_nx][blue_ny] != 'O') {
					blue_nx += dx[i];
					blue_ny += dy[i];
				}
				if (red_nx == blue_nx && red_ny == blue_ny) {
					if (arr[red_nx][blue_ny] == 'O')
						continue;
					if (abs(red_nx - redball_x) + abs(red_ny - redball_y) < abs(blue_nx - blueball_x) + abs(blue_ny - blueball_y)) {
						blue_nx -= dx[i];
						blue_ny -= dy[i];
					}
					else {
						red_nx -= dx[i];
						red_ny -= dy[i];
					}
				}
				if (visit[red_nx][red_ny][blue_nx][blue_ny])
					continue;
				q.push(make_pair(make_pair(red_nx, red_ny), make_pair(blue_nx, blue_ny)));
				visit[red_nx][red_ny][blue_nx][blue_ny] = true;
			}
		}
		if (result == 10)
			return -1;
		result++;
	}
	return -1;
}
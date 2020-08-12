#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int N, M, K;
int map[1000][1000];
int dX[] = { -1, 0, 1, 0 };
int dY[] = { 0, -1, 0, 1 };
bool visited[11][1000][1000] = { false, };

void bfs();

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	bfs();

	return 0;
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = true;

	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int cnt = q.front().second.first; //벽을 부순 횟수
		int move_dis = q.front().second.second; //이동거리

		q.pop();

		if (curX == N - 1 && curY == M - 1) {
			cout << move_dis;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (map[nextX][nextY] == 0) {
					if (!visited[cnt][nextX][nextY]) {
						visited[cnt][nextX][nextY] = true;
						q.push(make_pair(make_pair(nextX, nextY), make_pair(cnt, move_dis + 1)));
					}
				}
				else if (map[nextX][nextY] == 1) {
					if (cnt < K) {
						if (!visited[cnt + 1][nextX][nextY]) {
							visited[cnt + 1][nextX][nextY] = true;
							q.push(make_pair(make_pair(nextX, nextY), make_pair(cnt + 1, move_dis + 1)));
						}
					}
				}
			}
		}
	}
	cout << -1;
}
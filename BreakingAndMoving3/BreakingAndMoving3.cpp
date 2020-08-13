#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <tuple>
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
	queue<tuple<pair<int, int>, pair<int, int>, bool>> q;
	q.push(make_tuple(make_pair(0, 0), make_pair(0, 1), true));
	visited[0][0][0] = true;

	while (!q.empty()) {
		pair<int, int> pair1;
		pair<int, int> pair2;
		bool day;

		tie(pair1, pair2, day) = q.front();
		
		int curX = pair1.first;
		int curY = pair1.second;
		int cnt = pair2.first; //벽을 부순 횟수
		int move_dis = pair2.second; //이동거리

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
						q.push(make_tuple(make_pair(nextX, nextY), make_pair(cnt, move_dis + 1), !day));
					}
				}
				else if (map[nextX][nextY] == 1) {
					if (cnt < K) {
						if (!visited[cnt + 1][nextX][nextY]) {
							if (day) {
								visited[cnt + 1][nextX][nextY] = true;
								q.push(make_tuple(make_pair(nextX, nextY), make_pair(cnt + 1, move_dis + 1), !day));
							}
							else {
								q.push(make_tuple(make_pair(curX, curY), make_pair(cnt, move_dis + 1), !day));
							}
						}
					}
				}
			}
		}
	}
	cout << -1;
}
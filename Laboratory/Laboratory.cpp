#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M, zeroCnt, ans;
int dX[] = { 1,0,-1,0 };
int dY[] = { 0,1,0,-1 };

int map[9][9], tmp[9][9];
queue<pair<int, int>> base;

void dfs(int n, int zero);
void bfs(int zCnt);

int main()
{
	cin >> N >> M;
	zeroCnt = N * M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				--zeroCnt;
				if (map[i][j] == 2)
					base.push(make_pair(i, j));
			}
		}
	}
	
	memcpy(tmp, map, sizeof(map));
	dfs(0, zeroCnt);

	cout << ans;

	return 0;
}

void dfs(int n, int zero) {
	if (n == 3) {
		bfs(zero);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				--zero;
				dfs(n + 1, zero);
				tmp[i][j] = 0;
				++zero;
			}
		}
	}
}

void bfs(int zCnt) {
	int afterMap[9][9];
	memcpy(afterMap, tmp, sizeof(tmp));
	int zC = zCnt;
	queue<pair<int, int>> q = base;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];

			if (((nextX >= 0 && nextX < N) && (nextY >= 0 && nextY < M)) && afterMap[nextX][nextY] == 0) {
				afterMap[nextX][nextY] = 2;
				--zC;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
	ans = max(ans, zC);
}
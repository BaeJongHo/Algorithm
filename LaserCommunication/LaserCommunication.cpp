#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX 100
#define MIN 100000000

using namespace std;

int H, W;
int check = 0;
int result;
char map[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>> start_end;

int dX[4] = { -1,0, 1, 0 };
int dY[4] = { 0, 1,0, -1 };

void bfs();

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				start_end.push_back(make_pair(i, j));
			}
			visited[i][j] = MIN;
		}
	}

	bfs();

	cout << result;

    return 0;
}

void bfs() {
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < 4; i++)
		q.push(make_tuple(start_end[0].first, start_end[0].second, 0, i));
	visited[start_end[0].first][start_end[0].second] = 0;

	while (!q.empty()) {
		int cur_x, cur_y, refract, direction;
		tie(cur_x, cur_y, refract, direction) = q.front();

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dX[i];
			int ny = cur_y + dY[i];
			int nRefract = refract;

			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (map[nx][ny] != '*') {
					if (direction != i)
						nRefract += 1;
					if (visited[nx][ny] >= nRefract) {
						visited[nx][ny] = nRefract;
						q.push(make_tuple(nx, ny, nRefract, i));
					}
				}
			}
		}
	}
	result = visited[start_end[1].first][start_end[1].second];
}
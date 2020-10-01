#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;

int N;
int group1[MAX][MAX];
int group2[MAX][MAX];

char board[MAX][MAX];

int dX[4] = { -1,0,1,0 };
int dY[4] = { 0,1,0,-1 };

void bfs1();
void bfs2();

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	memset(group1, -1, sizeof(group1));
	bfs1();
	memset(group2, -1, sizeof(group2));
	bfs2();

	return 0;
}

void bfs1() {
	queue<pair<int, int>> q;
	int idx = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (group1[i][j] == -1) {
				
				q.push(make_pair(i, j));
				group1[i][j] = idx;

				while (!q.empty()) {
					int cur_x = q.front().first;
					int cur_y = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int next_x = cur_x + dX[k];
						int next_y = cur_y + dY[k];

						if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
							if (group1[next_x][next_y] == -1) {
								if (board[cur_x][cur_y] == board[next_x][next_y]) {
									group1[next_x][next_y] = idx;
									q.push(make_pair(next_x, next_y));
								}
							}
						}
					}
				}
				idx++;
			}
		}
	}

	cout << idx - 1 << " ";
}

void bfs2() {
	queue<pair<int, int>> q;
	int idx = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (group2[i][j] == -1) {

				q.push(make_pair(i, j));
				group2[i][j] = idx;

				while (!q.empty()) {
					int cur_x = q.front().first;
					int cur_y = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int next_x = cur_x + dX[k];
						int next_y = cur_y + dY[k];

						if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
							if (group2[next_x][next_y] == -1) {
								if (board[cur_x][cur_y] == 'R' || board[cur_x][cur_y] == 'G') {
									if (board[next_x][next_y] == 'R' || board[next_x][next_y] == 'G') {
										group2[next_x][next_y] = idx;
										q.push(make_pair(next_x, next_y));
									}
								}
								else if (board[cur_x][cur_y] == 'B' && board[next_x][next_y] == 'B') {
									group2[next_x][next_y] = idx;
									q.push(make_pair(next_x, next_y));
								}
							}
						}
					}
				}
				idx++;
			}
		}
	}

	cout << idx - 1;
}
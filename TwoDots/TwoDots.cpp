#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
char board[51][51];
bool visited[51][51];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

bool check(int i, int j, int by, int bx, char alp)
{

	if (visited[i][j])
		return true;

	visited[i][j] = true;

	bool ret = false;
	for (int k = 0; k < 4; ++k) {
		int ny = i + dy[k];
		int nx = j + dx[k];

		if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
			continue;
		if (ny == by && nx == bx)
			continue;
		if (alp != board[ny][nx])
			continue;

		ret += check(ny, nx, i, j, alp);
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (visited[i][j])
				continue;

			if (check(i, j, -1, -1, board[i][j])) {
				cout << "Yes";
				return 0;
			}
		}
	cout << "No";
	return 0;
}
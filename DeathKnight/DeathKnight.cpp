#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N;
int r1, c1, r2, c2;
int r[6] = { -2, -2, 0, 0, 2, 2 };
int c[6] = { -1, 1, -2, 2, -1, 1 };
int board[201][201];
bool visited[201][201];

void bfs();

int main()
{
	cin >> N;

	cin >> r1 >> c1 >> r2 >> c2;

	bfs();
}

void bfs() {
	int check = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(r1, c1, 0));

	visited[r1][c1] = true;

	while (!q.empty()) {
		int temp_r = get<0>(q.front());
		int temp_c = get<1>(q.front());
		int cnt = get<2>(q.front());

		if (temp_r == r2 && temp_c == c2) {
			cout << cnt;
			check = 1;
			break;
		}

		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_r = temp_r + r[i];
			int next_c = temp_c + c[i];

			if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N || visited[next_r][next_c])
				continue;

			q.push(make_tuple(next_r, next_c, cnt + 1));
			visited[next_r][next_c] = true;
		}
	}

	if (check == 0)
		cout << -1;
}
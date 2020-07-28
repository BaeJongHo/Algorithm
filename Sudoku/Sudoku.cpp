#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> points;
int cnt = 0;
bool found = false;

void dfs(int n);
bool check(pair<int, int> p);

int main() {
	pair<int, int> point;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				cnt++;
				point.first = i;
				point.second = j;
				points.push_back(point);
			}
		}
	}

	dfs(0);

	return 0;
}

void dfs(int n) {
	if (n == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << " ";
			cout << '\n';
		}
		found = true;
		return;
	}

	for (int j = 1; j <= 9; j++) {
		board[points[n].first][points[n].second] = j;

		if (check(points[n]))
			dfs(n + 1);

		if (found)
			return;

		board[points[n].first][points[n].second] = 0;
	}
}

bool check(pair<int, int> p) {
	int x = p.first / 3;
	int y = p.second / 3;

	for (int i = 0; i < 9; i++) {
		if (board[p.first][i] == board[p.first][p.second] && i != p.second)
			return false;
		if (board[i][p.second] == board[p.first][p.second] && i != p.first)
			return false;
	}

	for (int i = 3 * x; i < 3 * x + 3; i++) {
		for (int j = 3 * y; j < 3 * y + 3; j++) {
			if (board[i][j] == board[p.first][p.second]) {
				if (i != p.first && j != p.second)
					return false;
			}
		}
	}
	return true;
}
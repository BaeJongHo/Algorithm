#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int puzzle_num = 0;
int N;
int board[9][9];
vector<pair<int, int>> points;
int cnt = 0;
bool found;

void dfs(int n);
bool check(pair<int, int> p);

int main() {
	string s;
	pair<int, int> point;
	
	while (1) {
		found = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				board[i][j] = 0;
		}

		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			int u, v;
			string lu, lv;

			cin >> u >> lu;
			cin >> v >> lv;

			int x = (int)lu.front() - 65;
			int y = (int)lu.back() - 49;
			board[x][y] = u;

			x = (int)lv.front() - 65;
			y = (int)lv.back() - 49;
			board[x][y] = v;
		}

		for (int i = 1; i < 10; i++) {
			cin >> s;
			int x = (int)s.front() - 65;
			int y = (int)s.back() - 49;
			board[x][y] = i;
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == 0) {
					cnt++;
					point.first = i;
					point.second = j;
					points.push_back(point);
				}
			}
		}

		dfs(0);
	}
	
	return 0;
}

void dfs(int n) {
	if (n == cnt) {
		cout << "Puzzle " << ++puzzle_num;
		cout << "\n";
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			if(i != 8)
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
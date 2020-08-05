#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int T;
vector<pair<int, int>> v;
bool visited[10000] = { false, };

void bfs(int A, int B, string res);

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for (int i = 0; i < T; i++) {
		memset(visited, false, sizeof(visited));
		bfs(v[i].first, v[i].second, "");
	}

	return 0;
}

void bfs(int A, int B, string res) {
	queue<pair<pair<int, int>, string>> q;
	q.push(make_pair(make_pair(A, B), res));
	visited[A] = true;

	while (!q.empty()) {
		int change = q.front().first.first;
		int des = q.front().first.second;
		string result = q.front().second;

		q.pop();

		if (change == des) {
			cout << result << "\n";
			return;
		}

		//D
		int next_change = (2 * change) % 10000;
		if (!visited[next_change]) {
			visited[next_change] = true;
			q.push(make_pair(make_pair(next_change, des), result + "D"));
		}
		//S
		next_change = change - 1;
		if (next_change == -1)
			next_change = 9999;
		if (!visited[next_change]) {
			visited[next_change] = true;
			q.push(make_pair(make_pair(next_change, des), result + "S"));
		}
		//L
		next_change = (change % 1000) * 10 + (change / 1000);
		if (!visited[next_change]) {
			visited[next_change] = true;
			q.push(make_pair(make_pair(next_change, des), result + "L"));
		}
		//R
		next_change = (change % 10) * 1000 + (change / 10);
		if (!visited[next_change]) {
			visited[next_change] = true;
			q.push(make_pair(make_pair(next_change, des), result + "R"));
		}
	}
}
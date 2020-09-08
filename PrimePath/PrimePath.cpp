#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int T;
vector<pair<string, string>> tCase;
bool visited[10000] = { false, };

void bfs(string start, string end);
bool checkPrime(int nVal);

int main()
{
	

	cin >> T;

	for (int i = 0; i < T; i++) {
		string a, b;
		cin >> a >> b;
		tCase.push_back(make_pair(a, b));
	}

	for (int i = 0; i < T; i++) {
		memset(visited, false, sizeof(visited));
		bfs(tCase[i].first, tCase[i].second);
	}

	return 0;
}

void bfs(string start, string end) {
	queue<pair<string, int>> q;
	q.push(make_pair(start, 0));
	visited[atoi(start.c_str())] = true;

	while (!q.empty()) {
		string val;
		int cnt;
		val = q.front().first;
		cnt = q.front().second;

		q.pop();

		if (val == end) {
			cout << cnt << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string temp = val;
				if (temp[i] - '0' != j) {
					if (i == 0 && j == 0)
						continue;

					temp[i] = j + '0';
					if (!visited[atoi(temp.c_str())]) {
						visited[atoi(temp.c_str())] = true;
						if (checkPrime(atoi(temp.c_str()))) {
							q.push(make_pair(temp, cnt + 1));
						}
					}
				}
			}
		}
	}
	cout << "Impossible\n";
}

bool checkPrime(int nVal) {
	int nHalf = nVal / 2 + 1;

	for (int i = 2; i < nHalf; i++) {
		if (nVal % i == 0)
			return false;
	}

	return true;
}
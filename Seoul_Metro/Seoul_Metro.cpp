#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool inLoop[3001];
bool visited[3001];
int N;
vector<int> v[3001];
bool cycle(int idx, int pre, int start);
int bfs(int start);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		if (cycle(i, -1, i)) {
			inLoop[i] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		cout << bfs(i) << " ";
	}
	return 0;
}

bool cycle(int idx, int pre, int start) {

	if (idx == start && visited[idx])
		return true;

	visited[idx] = true;

	bool res = false;

	for (int i = 0; i < v[idx].size(); i++) {
		int idx2 = v[idx][i];
		if (idx2 == pre)
			continue;
		else if (visited[idx2] && idx2 != start)
			continue;

		res = (res ? true : cycle(idx2, idx, start));
	}

	return res;
}

int bfs(int start) {
	typedef pair<int, int> P;
	queue<P> q;
	q.push(P(start, 0));
	visited[start] = true;

	while (!q.empty()) {
		P p = q.front();
		q.pop();
		int idx = p.first, dist = p.second;

		if (inLoop[idx])
			return dist;

		for (int i = 0; i < v[idx].size(); i++) {
			int idx2 = v[idx][i];
			if (visited[idx2])
				continue;

			visited[idx2] = true;
			q.push(P(idx2, dist + 1));
		}
	}
	return -1;
}
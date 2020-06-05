#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> list;
int N, K;
bool visited[100001];
int dist[100001];
int m[3] = { -1, 1, 2 };

void bfs(int loca);
void dfs(int cur, int n);

int main()
{
	cin >> N >> K;

	bfs(N);
}

void bfs(int loca) {
	q.push(loca);
	dist[loca] = 0;
	visited[loca] = true;
	while (!q.empty()) {
		if (visited[K]) {
			memset(visited, false, sizeof(visited));
			dfs(loca, 0);
			break;
		}
		int cur = q.front();
		q.pop();

		int next;
		for (int i = 0; i < 3; i++) {
			if (i != 2)
				next = cur + m[i];
			else
				next = cur * m[i];

			if (next >= 0 && next <= 100000) {
				if (!visited[next]) {
					visited[next] = true;
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}

void dfs(int cur, int n) {
	list.push_back(cur);
	visited[cur] = true;

	if (n > dist[K])
		return;

	if (cur == K) {
		cout << dist[K] << "\n";
		for (int i = 0; i < list.size(); i++)
			cout << list[i] << " ";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		int next;
		if (i != 2)
			next = cur + m[i];
		else
			next = cur * m[i];

		if (next >= 0 && next <= 100000) {
			if (!visited[next]) {
				dfs(next, n + 1);
				visited[next] = false;
				list.pop_back();
			}
		}
	}
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;
int N, K;
bool visited[100001];
int dist[100001];
int m[3] = { -1, 1, 2 };

void bfs(int loca);

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
		if (visited[K])
			break;

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

	cout << dist[K];
}
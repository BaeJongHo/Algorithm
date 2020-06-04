#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;

deque<int> q;
int N, K;
bool visited[100001];
int dist[100001];
int m[3] = { 2, 1, -1 };

void bfs(int loca);

int main()
{
	cin >> N >> K;

	bfs(N);
}

void bfs(int loca) {
	q.push_back(loca);
	dist[loca] = 0;
	visited[loca] = true;

	while (!q.empty()) {

		if (visited[K])
			break;

		int cur = q.front();

		q.pop_front();

		int next;
		for (int i = 0; i < 3; i++) {
			if (i != 0)
				next = cur + m[i];
			else
				next = cur * m[i];

			if (next >= 0 && next <= 100000) {
				if (!visited[next]) {
					if (i != 0) {
						visited[next] = true;
						dist[next] = dist[cur] + 1;
						q.push_back(next);
					}
					else {
						visited[next] = true;
						dist[next] = dist[cur];
						q.push_front(next);
					}
				}
			}
		}
	}

	cout << dist[K];
}
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
int pre[100001];
int m[3] = { -1, 1, 2 };

void bfs(int loca);
void print(int n, int m);

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
			break;
		}

		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next;
			if (i != 2) {
				next = cur + m[i];
				if (next >= 0 && next <= 100000) {
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
						dist[next] = dist[cur] + 1;
						pre[next] = cur;
					}
				}
			}
			else {
				next = cur * m[i];
				if (next >= 0 && next <= 100000) {
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
						dist[next] = dist[cur] + 1;
						pre[next] = cur;
					}
				}
			}
		}
	}

	cout << dist[K] << "\n";
	print(N, K);
}

void print(int n, int m) {
	if (n != m)
		print(n, pre[m]);

	cout << m << " ";
}
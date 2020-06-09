#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
long long W[11][11];
long long mini = 100000000;
long long cost;
int start;
bool visited[11];

void dfs(int idx, int n);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		cost = 0;
		start = i;
		dfs(i, 1);
	}

	cout << mini;
}

void dfs(int idx, int n) {
	if (n == N) {
		if (W[idx][start] != 0) {
			cost += W[idx][start];
			mini = min(mini, cost);
			cost -= W[idx][start];
			return;
		}
		else
			return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && W[idx][i] != 0) {
			visited[i] = true;
			cost += W[idx][i];
			dfs(i, n + 1);
			visited[i] = false;
			cost -= W[idx][i];
		}
	}
}
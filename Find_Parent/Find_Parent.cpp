#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
bool visited[100001];
vector<int> tree[100001];
int parent[100001];

void dfs(int cur);

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}

void dfs(int cur) {
	visited[cur] = true;

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (!visited[next]) {
			parent[next] = cur;
			dfs(next);
		}
	}
}
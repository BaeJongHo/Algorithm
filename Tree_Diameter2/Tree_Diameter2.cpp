#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001];
int diameter = 0;
int last_node;

void dfs(int cur, int d);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int node1, node2, dis;
		cin >> node1 >> node2 >> dis;
		tree[node1].push_back({ node2, dis });
		tree[node2].push_back({ node1, dis });
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(last_node, 0);

	cout << diameter;
}

void dfs(int cur, int d) {
	visited[cur] = true;

	if (diameter < d) {
		diameter = d;
		last_node = cur;
	}

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i].first;
		int dis = tree[cur][i].second;
		if (!visited[next]) {
			dfs(next, d + dis);
		}
	}
}
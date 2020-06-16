#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int V;
vector<pair<int, int>> tree[100001];
bool visited[100001];
int diameter = 0;
int last_node;

void dfs(int cur, int d);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V;

	for (int i = 0; i < V; i++) {
		int node1;
		cin >> node1;
		while (1) {
			int node2, dis;
			cin >> node2;
			if (node2 == -1)
				break;
			cin >> dis;

			tree[node1].push_back({ node2, dis });
		}
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
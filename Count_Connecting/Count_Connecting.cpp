#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[1001];
bool visited[1001];

void dfs(int idx);

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int check = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			check++;
		}
	}

	cout << check;

	return 0;
}

void dfs(int idx) {
	visited[idx] = true;

	for (int i = 0; i < graph[idx].size(); i++) {
		int idx2 = graph[idx][i];
		if (!visited[idx2])
			dfs(idx2);
	}
}
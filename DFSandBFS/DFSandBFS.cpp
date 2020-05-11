#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, V;
int mat[1001][1001];
queue<int> list;
bool visited[1001];

void dfs(int idx);
void bfs(int idx);

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	memset(visited, false, sizeof(visited));
	visited[V] = true;
	dfs(V);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	visited[V] = true;
	bfs(V);

	return 0;
}

void dfs(int idx) {
	cout << idx << " ";
	for (int i = 1; i <= N; i++) {
		if (mat[idx][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i);
		}
	}
}

void bfs(int idx) {
	list.push(idx);

	while (!list.empty()){
		idx = list.front();
		list.pop();

		cout << idx << " ";

		for (int i = 1; i <= N; i++) {
			if (mat[idx][i] && !visited[i]){
				visited[i] = true;
				list.push(i);
			}
		}
	}
}

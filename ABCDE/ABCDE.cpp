#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool visited[2000], answer = false;
vector<int> v[2000];

void dfs(int idx, int n);

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
		if (answer)
			break;
	}

	if (answer)
		cout << 1;
	else
		cout << 0;

	return 0;
}

void dfs(int idx, int n) {
	if (n == 4) {
		answer = true;
		return;
	}

	visited[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int idx2 = v[idx][i];
		if (!visited[idx2]) {
			dfs(idx2, n + 1);
		}
		if (answer)
			return;
	}
	visited[idx] = false;
}

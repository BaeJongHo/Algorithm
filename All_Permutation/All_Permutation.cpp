#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool visited[9];
vector<int> v;

void dfs(int n);

int main()
{
	cin >> N;

	dfs(0);
}

void dfs(int n) {

	if (n == N) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			dfs(n + 1);
			visited[i] = false;
			v.pop_back();
		}
	}
}
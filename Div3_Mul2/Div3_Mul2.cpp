#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> v;
vector<long long> list;
bool visited[101];
int N;

void dfs(int idx, int n);

int main()
{
    cin >> N;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		dfs(i, 1);
	}
}

void dfs(int idx, int n) {
	visited[idx] = true;
	list.push_back(v[idx]);

	if (n == v.size()) {
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << " ";
		}
		exit(0);
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[idx] % 3 == 0 && v[idx] / 3 == v[i] && idx != i && !visited[i]) {
			dfs(i, n + 1);
		}

		if (v[idx] * 2 == v[i] && idx != i && !visited[i]) {
			dfs(i, n + 1);
		}
	}
	visited[idx] = false;
	list.pop_back();
}
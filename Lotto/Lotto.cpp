#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int k;
vector<int> v;
vector<int> list;
bool visited[13];

void dfs(int n);

int main()
{
	while (1) {
		cin >> k;

		if (k == 0)
			break;

		v.clear();
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		dfs(0);
		cout << "\n";
	}
}

void dfs(int n) {

	if (n == 6) {
		int asc = 0;
		for (int i = 0; i < list.size() - 1; i++) {
			if (list[i] > list[i + 1])
				asc++;
		}

		if (asc > 0) {

		}
		else {
			for (int i = 0; i < list.size(); i++)
				cout << list[i] << " ";
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			list.push_back(v[i]);
			dfs(n + 1);
			visited[i] = false;
			list.pop_back();
		}
	}
}
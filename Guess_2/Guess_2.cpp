#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n;
char a[10][10];
vector<int> v;

void dfs(int idx);
bool possible(int idx);

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dfs(0);

	return 0;
}

void dfs(int idx) {
	if (idx == n) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		exit(0);
	}

	for (int i = -10; i < 11; i++) {
		v.push_back(i);
		if (possible(idx))
			dfs(idx + 1);
		v.pop_back();
	}
}

bool possible(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += v[i];

		if (a[i][idx] == '+' && sum <= 0)
			return false;

		if (a[i][idx] == '0' && sum != 0)
			return false;

		if (a[i][idx] == '-' && sum >= 0)
			return false;
	}
	return true;
}
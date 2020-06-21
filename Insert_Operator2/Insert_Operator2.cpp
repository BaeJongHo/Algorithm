#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000000;

using namespace std;

int N;
int maxi = -MAX;
int mini = MAX;
vector<int> v, op;

void dfs(int n, int ret);
int cal(int i, int n, int ret);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		op.push_back(a);
	}

	dfs(1, v[0]);

	cout << maxi << "\n";
	cout << mini;

	return 0;
}

void dfs(int n, int ret) {
	if (n == v.size()) {
		maxi = max(maxi, ret);
		mini = min(mini, ret);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i]--;
			dfs(n + 1, cal(i, n, ret));
			op[i]++;
		}
	}
}

int cal(int i, int n, int ret) {
	if (i == 0)
		return ret + v[n];
	else if (i == 1)
		return ret - v[n];
	else if (i == 2)
		return ret * v[n];
	else
		return ret / v[n];
}
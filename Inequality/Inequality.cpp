#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

vector<char> v;
string list;
bool visited[10];
int k;
long long maxi = 0;
long long mini = 100000000000;

void dfs(int idx, int n);

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++) {
		char a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < 10; i++) {
		list.clear();
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
	}

	cout << maxi << "\n";
	if (mini < pow(10, k))
		cout << 0 << mini;
	else
		cout << mini;
}

void dfs(int idx, int n) {
	list.push_back('0' + idx);
	visited[idx] = true;

	if (n == k) {
		long long num = stoll(list);

		if (maxi < num)
			maxi = num;
		
		if (mini > num)
			mini = num;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (v[n] == '>' && idx != i && !visited[i]) {
			if (idx > i) {
				dfs(i, n + 1);
				list.pop_back();
				visited[i] = false;
			}
		}
		else if (v[n] == '<' && idx != i && !visited[i]) {
			if (idx < i) {
				dfs(i, n + 1);
				list.pop_back();
				visited[i] = false;
			}
		}
	}
}
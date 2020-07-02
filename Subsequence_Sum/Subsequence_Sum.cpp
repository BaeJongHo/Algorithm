#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
vector<int> list;
bool visited[21];
int cnt = 0;

void dfs(int n);

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	dfs(0);

	cout << cnt;
}

void dfs(int ret) {
	if (ret == S) {
		if (list.empty()) {
		}
		else {
			int chk = 0;
			for (int i = 0; i < list.size() - 1; i++) {
				if (list[i] > list[i + 1])
					chk++;
			}

			if(chk == 0)
				cnt++;
			return;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			list.push_back(v[i]);
			dfs(ret + v[i]);
			list.pop_back();
			visited[i] = false;
		}
	}
}
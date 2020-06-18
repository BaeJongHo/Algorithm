#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> v;
bool visited[100];
bool visited_num[10];
int match[100];
int length;
vector<char> str;
long long ans = 0;

void dfs(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			str.push_back(v[i][j]);
	}

	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	length = str.size();

	memset(visited, false, sizeof(visited));
	memset(visited_num, false, sizeof(visited_num));
	memset(match, 0, sizeof(match));
	dfs(0);

	cout << ans;
}

void dfs(int n) {
	if (n == length) {
		long long temp = 0;
		for (int i = 0; i < v.size(); i++) {
			string s;
			for (int j = 0; j < v[i].size(); j++) {
				s.push_back('0' + match[v[i][j]]);
			}
			long long num = stoll(s);
			temp += num;
		}
		ans = max(temp, ans);
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (!visited[str[n]] && !visited_num[i]) {
			visited[str[n]] = true;
			visited_num[i] = true;
			match[str[n]] = i;
			dfs(n + 1);
			visited[str[n]] = false;
			visited_num[i] = false;
			match[str[n]] = 0;
		}
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> list;
vector<char> o;
int oper[4];
int length = 0;
bool visited[11];
long long maxi = 0;
long long mini = 100000000;

void dfs(int n);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		length += a;
		oper[i] = a;
	}

	dfs(0);

	cout << maxi << "\n";
	cout << mini;
}

void dfs(int n) {
	if (n == length) {
		long long result = list[0];
		for (int i = 0; i < list.size() - 1; i++) {
			if (o[i] == '+')
				result += list[i + 1];
			else if (o[i] == '-')
				result -= list[i + 1];
			else if (o[i] == '*')
				result *= list[i + 1];
			else {
				if (result < 0 && list[i + 1] > 0) {
					result = abs(result) / list[i + 1];
					result = -result;
				}
				else
					result /= list[i + 1];
			}

			if (result < -1000000000 && result > 1000000000)
				break;
		}

		if (result < -1000000000 && result > 1000000000)
			return;

		maxi = max(maxi, result);
		mini = min(mini, result);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			if (i == 0)
				o.push_back('+');
			else if (i == 1)
				o.push_back('-');
			else if (i == 2)
				o.push_back('*');
			else
				o.push_back('/');
			dfs(n + 1);
			oper[i]++;
			o.pop_back();
		}
	}
}
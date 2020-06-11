#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<char> v;
vector<int> list;
bool visited[21];
int A[21];

void dfs(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N * (N + 1) / 2; i++) {
		char a;
		cin >> a;
		v.push_back(a);
	}

	int temp = -10;
	for (int i = 0; i < 21; i++) {
		A[i] = temp;
		temp++;
	}

	dfs(0);
}

void dfs(int n) {
	if (n == N) {

		int s = 0;
		bool check = true;

		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				int sum = 0;
				char signal;

				for (int k = i; k <= j; k++) {
					sum += list[k];
				}

				if (sum < 0)
					signal = '-';
				else if (sum > 0)
					signal = '+';
				else
					signal = '0';

				if (signal != v[s]){
					check = false;
					break;
				}
				s++;
			}
		}

		if (check) {
			for (int i = 0; i < list.size(); i++)
				cout << list[i] << " ";
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 21; i++) {
		if (!visited[i]) {
			visited[i] = true;
			list.push_back(A[i]);
			dfs(n + 1);
			visited[i] = false;
			list.pop_back();
		}
	}
}
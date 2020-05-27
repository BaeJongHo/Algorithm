#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int status[21][21];
vector<int> v;
int difference = 100000;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		v.push_back(i + 1);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> status[i][j];
	}

	do {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < (v.size() / 2) - 1; i++) {
			for (int j = i; j < (v.size() / 2) - 1; j++) {
				sum1 += status[v[i]][v[j + 1]];
				sum1 += status[v[j + 1]][v[i]];
			}
		}

		for (int i = v.size() / 2; i < v.size() - 1; i++) {
			for (int j = i; j < v.size() - 1; j++) {
				sum2 += status[v[i]][v[j + 1]];
				sum2 += status[v[j + 1]][v[i]];
			}
		}

		if (difference > abs(sum1 - sum2))
			difference = abs(sum1 - sum2);
	} while (next_permutation(v.begin(), v.end()));

	cout << difference;
}
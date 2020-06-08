#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<int> list;
int ans = 0;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}

	sort(list.begin(), list.end());

	do {
		int sum = abs(list[0] - list[1]);
		for (int i = 1; i < list.size() - 1; i++) {
			sum += abs(list[i] - list[i + 1]);
		}
		ans = max(ans, sum);
	} while (next_permutation(list.begin(), list.end()));

	cout << ans;
}
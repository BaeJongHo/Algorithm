#include <iostream>
#include <algorithm>

using namespace std;

int N;
int* term;
int* price;
int ans = 0;

void schedule(int idx, int p);

int main()
{
	cin >> N;

	term = new int[N];
	price = new int[N];

	for (int i = 0; i < N; i++)
		cin >> term[i] >> price[i];

	schedule(0, 0);

	cout << ans;

	return 0;
}

void schedule(int idx, int p) {
	if (idx == N) {
		ans = max(ans, p);
		return;
	}

	if (idx >= N)
		return;

	schedule(idx + term[idx], p + price[idx]);
	schedule(idx + 1, p);
}
#include <iostream>
#include <algorithm>

using namespace std;

int N;
char map[20][20];
int ans = 10000000000;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			map[i][j] = a;
		}
	}

	for (int k = 0; k < (1 << N); k++) {
		int sum = 0;

		for (int j = 0; j < N; j++) {
			int nowT = 0;

			for (int i = 0; i < N; i++) {
				char now = map[i][j];

				if ((1 << i) & k) {
					if (now == 'T')
						now = 'H';
					else
						now = 'T';
				}

				if (now == 'T')
					nowT++;
			}

			sum += min(nowT, N - nowT);
		}
		ans = min(ans, sum);
	}

	cout << ans;

	return 0;
}
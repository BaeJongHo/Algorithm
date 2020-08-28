#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> coinSet;

void flip(int instance, int idx);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		coinSet.push_back(s);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				if (k == 0) {
					int T_count = 0, H_count = 0;
					for (int idx = 0; idx < N; idx++) {
						if (coinSet[i][idx] == 'T')
							T_count++;
						else
							H_count++;
					}
					if (T_count > H_count)
						flip(k, i);
				}
				else {
					int T_count = 0, H_count = 0;
					for (int idx = 0; idx < N; idx++) {
						if (coinSet[idx][j] == 'T')
							T_count++;
						else
							H_count++;
					}
					if (T_count > H_count)
						flip(k, j);
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (coinSet[i][j] == 'T')
				res++;
		}
	}
	cout << res;
	
	return 0;
}

void flip(int instance, int idx) {
	if (instance == 0) {
		for (int h = 0; h < N; h++) {
			if (coinSet[idx][h] == 'T')
				coinSet[idx][h] = 'H';
			else
				coinSet[idx][h] = 'T';
		}
	}
	else {
		for (int h = 0; h < N; h++) {
			if (coinSet[h][idx] == 'T')
				coinSet[h][idx] = 'H';
			else
				coinSet[h][idx] = 'T';
		}
	}
}
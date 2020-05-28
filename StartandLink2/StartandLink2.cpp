#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int status[21][21];
bool visited[21];
int difference = 10000000;

void comb(int cnt, int cur) {
	if (cnt == N / 2) {
		int start_sum = 0;
		int link_sum = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i] && visited[j]) {
					start_sum += status[i][j];
					start_sum += status[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					link_sum += status[i][j];
					link_sum += status[j][i];
				}
			}
		}

		difference = min(difference, abs(start_sum - link_sum));
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false && i > cur) {
			visited[i] = true;
			comb(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}

	comb(0, -1);

	cout << difference;
}
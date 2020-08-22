#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
bool A[50][50];
bool B[50][50];

void XOR(int y, int x);

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			if (temp[j] == '0')
				A[i][j] = 0;
			else
				A[i][j] = 1;
	}

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			if (temp[j] == '0')
				B[i][j] = 0;
			else
				B[i][j] = 1;
	}

	int cnt = 0;
	bool change = false;

	if (N >= 3 && M >= 3) {
		for (int i = 0; i <= N - 3; i++) {
			for (int j = 0; j <= M - 3; j++) {
				if (A[i][j] != B[i][j]) {
					XOR(i, j);
					cnt++;
				}

				bool same = true;

				for (int x = 0; x < N; x++) {
					for (int y = 0; y < M; y++) {
						if (A[x][y] != B[x][y]) {
							same = false;
							break;
						}
					}
				}

				if (same == true) {
					change = true;
					break;
				}
			}
			if (change)
				break;
		}
	}
	else {
		change = true;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (A[x][y] != B[x][y])
					change = false;
			}
		}
	}

	if (change)
		cout << cnt << "\n";
	else
		cout << -1 << "\n";

	return 0;
}

void XOR(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			int temp = A[i][j];
			A[i][j] = 1 - temp;
		}
	}
}
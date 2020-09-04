#include <iostream>

using namespace std;

int N;
void hanoi(int n, int start, int to, int bypass);

int main() {
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 3, 2);
}

void hanoi(int n, int start, int to, int bypass) {
	if (n == 1) {
		cout << start << " ";
		cout << to << "\n";
	}
	else {
		hanoi(n - 1, start, bypass, to);
		cout << start << " ";
		cout << to << "\n";
		hanoi(n - 1, bypass, to, start);
	}
}
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int A, B, C, sum;
bool visited[1000][1000] = { false, };
int check = 0;

void bfs();

int main()
{
	cin >> A >> B >> C;
	sum = A + B + C;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	else
		bfs();

	return 0;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(A, B));
	visited[A][B] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;

		q.pop();

		if (x == y && y == z) {
			cout << 1;
			return;
		}
		
		int nx[] = { x, x, y };
		int ny[] = { y, z, z };

		for (int i = 0; i < 3; i++) {
			int a = nx[i], b = ny[i];
			if (a < b) {
				b -= a;
				a += a;
			}
			else if (a > b) {
				a -= b;
				b += b;
			}
			else
				continue;

			int c = sum - a - b;
			int X = min(min(a, b), c);
			int Y = max(max(a, b), c);
			if (!visited[X][Y]) {
				visited[X][Y] = true;
				q.push(make_pair(X, Y));
			}
		}
	}
	cout << 0;
}
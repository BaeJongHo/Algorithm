#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
int* visited;
char* list;
char* arr;

void dfs(int n);

int main()
{
	cin >> L >> C;

	visited = new int[C];
	for (int i = 0; i < C; i++)
		visited[i] = 0;

	list = new char[L];

	arr = new char[C];
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);

	dfs(0);

	return 0;
}

void dfs(int n) {
	if (n == L) {
		int check = 0;
		for (int i = 0; i < L - 1; i++) {
			if (list[i] > list[i + 1])
				check++;
		}

		if (check > 0) {
		}
		else {
			for (int i = 0; i < L; i++) {
				cout << list[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < C; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			list[n] = arr[i];
			dfs(n + 1);
			visited[i] = 0;
		}
	}
}
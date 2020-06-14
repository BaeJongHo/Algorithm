#include <iostream>
#include <algorithm>

using namespace std;

int N, nodeIdx;
int node[10001];
int low[10001];
int high[10001];
pair<int, int> tree[10001];

void dfs(int nodeNum, int n);

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 10001; i++)
		low[i] = 1000000;

	for (int i = 0; i < N; i++) {
		int parent, left, right;

		cin >> parent >> left >> right;
		
		node[parent]++;

		if (left != -1)
			node[left]++;
		tree[parent].first = left;

		if (right != -1)
			node[right]++;
		tree[parent].second = right;
	}

	int root;
	for (int i = 1; i <= N; i++)
		if (node[i] == 1)
			root = i;

	nodeIdx = 1;
	dfs(root, 1);

	int result = high[1] - low[1] + 1;
	int level = 1;
	for (int i = 2; i <= N; i++) {
		int temp = high[i] - low[i] + 1;
		if (temp > result) {
			result = temp;
			level = i;
		}
	}

	cout << level << " " << result;

	return 0;
}

void dfs(int nodeNum, int n) {

	if (tree[nodeNum].first != -1)
		dfs(tree[nodeNum].first, n + 1);

	low[n] = min(low[n], nodeIdx);
	high[n] = max(high[n], nodeIdx);
	nodeIdx++;

	if (tree[nodeNum].second != -1)
		dfs(tree[nodeNum].second, n + 1);
}
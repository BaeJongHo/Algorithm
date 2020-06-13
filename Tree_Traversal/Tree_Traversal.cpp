#include <iostream>
#include <algorithm>

using namespace std;

int N;

struct node
{
	char left;
	char right;
};

struct node arr[100];

void preOrder(char cur)
{
	if (cur == '.')
		return;
	else {
		cout << cur;
		preOrder(arr[cur].left);
		preOrder(arr[cur].right);
	}
}

void inOrder(char cur)
{
	if (cur == '.')
		return;
	else {
		inOrder(arr[cur].left);
		cout << cur;
		inOrder(arr[cur].right);
	}
}

void postOrder(char cur)
{
	if (cur == '.')
		return;
	else {
		postOrder(arr[cur].left);
		postOrder(arr[cur].right);
		cout << cur;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	char cur, left, right;

	for (int i = 1; i <= N; i++)
	{
		cin >> cur >> left >> right;
		arr[cur].left = left;
		arr[cur].right = right;
	}

	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');
	cout << "\n";
}
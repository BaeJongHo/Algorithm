#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
char arr[16];

void create(int idx, int n, int vowel, int cons, string s);

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);

	create(0, 0, 0, 0, "");
	return 0;
}

void create(int idx, int n, int vowel, int cons, string s) {
	if (n == L) {
		if (vowel >= 1 && cons >= 2)
			cout << s << endl;
		return;
	}
	
	if (idx == C)
		return;

	if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
		create(idx + 1, n + 1, vowel + 1, cons, s + arr[idx]);
	else
		create(idx + 1, n + 1, vowel, cons + 1, s + arr[idx]);
	create(idx + 1, n, vowel, cons, s);
}
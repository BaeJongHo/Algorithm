#include <iostream>
#include <string>

using namespace std;

int N, k;
int cnt = 0;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		string s = to_string(i);
		cnt += s.size();
		if (k <= cnt) {
			cout << s[s.size() - (cnt - k)];
			return 0;
		}
	}
	cout << -1;

    return 0;
}
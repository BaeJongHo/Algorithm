#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> s;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (s.find(a) == s.end())
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}

    return 0;
}
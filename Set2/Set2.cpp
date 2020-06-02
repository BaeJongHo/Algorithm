#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <string>

using namespace std;

bool S[21];
int M;

void calculate(string s, int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	memset(S, false, sizeof(S));
	for (int i = 0; i < M; i++) {
		string str;
		int a = 0;
		cin >> str;
		if (str != "all" && str != "empty")
			cin >> a;
		else if (str == "add" && S[a])
			continue;

		calculate(str, a);
	}

	return 0;
}

void calculate(string s, int num) {
	if (s == "add") {
		S[num] = true;
	}
	else if (s == "remove") {
		S[num] = false;
	}
	else if (s == "check") {
		if (S[num])
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else if (s == "toggle") {
		if (S[num])
			S[num] = false;
		else
			S[num] = true;
	}
	else if (s == "all") {
		memset(S, true, sizeof(S));
	}
	else if (s == "empty") {
		memset(S, false, sizeof(S));
	}
}
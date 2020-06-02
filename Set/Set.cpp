#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <string>

using namespace std;

set<int> S;
int M;

void calculate(string s, int num);

int main()
{
	cin >> M;

	for (int i = 0; i < M; i++) {
		string str;
		int a = 0;
		cin >> str;
		if (str != "all" && str != "empty")
			cin >> a;
		calculate(str, a);
	}

	return 0;
}

void calculate(string s, int num) {
	if (s == "add") {
		S.insert(num);
	}
	else if (s == "remove") {
		S.erase(num);
	}
	else if (s == "check") {
		int c = S.count(num);
		if (c > 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else if (s == "toggle") {
		int c = S.count(num);
		if (c > 0)
			S.erase(num);
		else
			S.insert(num);
	}
	else if (s == "all") {
		S.clear();
		for (int i = 1; i <= 20; i++) {
			S.insert(i);
		}
	}
	else if (s == "empty") {
		S.clear();
	}
}
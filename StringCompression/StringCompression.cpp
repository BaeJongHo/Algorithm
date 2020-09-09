#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

int main() {
	string s;

	cin >> s;

	int answer = s.length();

	if (s.length() == 1)
		return 1;

	for (int i = 1; i <= s.length() / 2; i++) {
		int count = 1;
		string temp = s.substr(0, i);
		string cmp, s2;

		for (int j = i; j < s.length(); j += i) {
			cmp = s.substr(j, i);

			if (temp == cmp)
				count++;
			else {
				if (count == 1) {
					s2 += temp;
					temp = cmp;
				}
				else {
					s2 += to_string(count) + temp;
					temp = cmp;
					count = 1;
				}
			}

			if (j + i >= s.length()) {
				if (count != 1) {
					s2 += to_string(count) + temp;
					break;
				}
				else {
					s2 += s.substr(j);
					break;
				}
			}
		}
		answer = min(answer, (int)s2.length());
	}

	cout << answer;

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkRight(string s);
bool checkBalance(string s);
string changeStr(string s, string s2);
string divideStr(string p);

int main()
{
	string p;
	cin >> p;
	string answer = "";

	if (checkRight(p)) {
		cout << p;
		return 0;
	}

	answer += divideStr(p);

	cout << answer;


	return 0;
}

string divideStr(string p) {
	string temp = "";
	for (int i = 1; i < p.size();) {
		string u, v;
		u = p.substr(0, i * 2);
		v = p.substr(i * 2);

		if (checkBalance(u) && checkBalance(v)) {
			if (checkRight(u)) {
				temp += u;
				temp += divideStr(v);
			}
			else {
				u = changeStr(u, v);
				temp += u;
			}
			break;
		}
		else
			i++;
	}

	return temp;
}

bool checkRight(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
		}

		if (cnt < 0)
			return false;
	}

	return true;
}

bool checkBalance(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
		}
	}

	if (cnt == 0)
		return true;
	else
		return false;
}

string changeStr(string s, string s2) {
	string temp = "";
	
	temp += "(";
	if (s2 != "") {
		if (checkRight(s2))
			temp += s2;
		else
			temp += divideStr(s2);
	}
	temp += ")";

	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '(')
			temp += ")";
		else
			temp += "(";
	}

	return temp;
}
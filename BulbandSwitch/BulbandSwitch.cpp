#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, answer = 100000000;
string s, copyS, result;

void push(int idx);
void simulation(int idx, int cnt);

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> s >> result;

	copyS = s;
	simulation(1, 0);

	copyS = s;
	push(0);
	simulation(1, 1);

	if (answer == 100000000)
		cout << -1;
	else
		cout << answer;

	return 0;
}

void push(int idx) {
	if (idx > 0)
		copyS[idx - 1] = (copyS[idx - 1] == '0') ? '1' : '0';

	copyS[idx] = (copyS[idx] == '0') ? '1' : '0';
	if (idx < N - 1)
		copyS[idx + 1] = (copyS[idx + 1] == '0') ? '1' : '0';

}

void simulation(int idx, int cnt) {
	if (idx == N - 1) {
		bool flag = true;

		for (int i = 0; i < copyS.length(); i++) {
			if (copyS[i] != result[i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer = min(answer, cnt);

		push(idx);
		flag = true;

		for (int i = 0; i < copyS.length(); i++) {
			if (copyS[i] != result[i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer = min(answer, cnt + 1);

		return;
	}

	if (copyS[idx - 1] == result[idx - 1])
		simulation(idx + 1, cnt);
	push(idx);

	if (copyS[idx - 1] == result[idx - 1])
		simulation(idx + 1, cnt + 1);
}
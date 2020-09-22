#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string N;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    int sum = 0;
    for (int i = 0; i < N.size(); i++) {
        sum += N[i] - '0';
    }

    sort(N.begin(), N.end(), greater<>());

    if (sum % 3 != 0 || N[N.size() - 1] != '0') {
        cout << -1 << endl;
        return 0;
    }

    cout << N << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string N;
vector<int> v;
int ans = 0;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    
    for (int i = 0; i < N.size(); i++) {
        int a = N[i] - '0';
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    
    if (sum % 3 != 0 || v[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    if (atoi(N.c_str()) % 30 == 0)
        ans = atoi(N.c_str());

    while (next_permutation(N.begin(), N.end())) {
        if (N[0] == '0' || N[N.size() - 1] != '0')
            continue;

        if (atoi(N.c_str()) % 30 == 0)
            ans = max(ans, atoi(N.c_str()));
    }

    cout << ans << endl;

    return 0;
}
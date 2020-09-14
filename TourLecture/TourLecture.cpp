#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int result = 0;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(d, p));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        result += v[i].second;
        pq.push(-v[i].second);
        if (pq.size() > v[i].first) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << endl;

    return 0;
}

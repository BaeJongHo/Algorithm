#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const long long MAX = 2000000000;
long long N, M;
long long ans = 0;

int dX[4] = { -2,-1,1,2 };
int dY[4] = { 1,2,2,1 };

void bfs(long long x, long long y);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    bfs(N - 1, 0);

    return 0;
}

void bfs(long long x, long long y) {
    queue<tuple<long long, long long, long long>> q;
    q.push(make_tuple(x, y, 1));

    while (!q.empty()) {
        long long cur_x, cur_y, cnt;
        tie(cur_x, cur_y, cnt) = q.front();

        q.pop(); 

        ans = max(ans, cnt);

        for (int i = 0; i < 4; i++) {
            long long next_x = cur_x + dX[i];
            long long next_y = cur_y + dY[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
                q.push(make_tuple(next_x, next_y, cnt + 1));
            }
        }
    }

    cout << ans << endl;
}
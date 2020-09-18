#include <iostream>

using namespace std;

int N, M, K;
int team_cnt = 0;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;

    while (1) {
        N -= 2;
        M -= 1;

        if (N >= 0 && M >= 0) {
            team_cnt++;
        }
        else
            break;
    }

    N += 2;
    M += 1;

    int intern = N + M;

    while (intern < K) {
        team_cnt--;
        intern += 3;
    }

    cout << team_cnt << endl;

    return 0;
}
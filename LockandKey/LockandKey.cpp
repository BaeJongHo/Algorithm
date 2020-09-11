#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, boardsize;

bool unlockKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board);
void rotation(vector<vector<int>>& key);

int main()
{
    bool answer = false;

    vector<vector<int>> key, lock;

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        key.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        vector<int> temp;
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        lock.push_back(temp);
    }

    N = key.size();
    M = lock.size();
    
    boardsize = M + (N - 1) * 2;
    vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));

    for (int i = N - 1; i <= boardsize - N; i++) {
        for (int j = N - 1; j <= boardsize - N; j++) {
            board[i][j] += lock[i - N + 1][j - N + 1];
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int i = 0; i <= boardsize - N; i++) {
            for (int j = 0; j <= boardsize - N; j++) {
                if (unlockKey(i, j, key, board)) {
                    answer = true;
                    cout << answer;
                    return 0;
                }
            }
        }

        rotation(key);
    }

    cout << answer;

    return 0;
}

bool unlockKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            board[i][j] += key[i - x][j - y];
        }
    }

    for (int i = N - 1; i <= boardsize - N; i++) {
        for (int j = N - 1; j <= boardsize - N; j++) {
            if (board[i][j] == 1)
                continue;

            return false;
        }
    }

    return true;
}

void rotation(vector<vector<int>>& key) {

    vector<vector<int>> temp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = key[N - j - 1][i];
        }
    }

    key = temp;
}
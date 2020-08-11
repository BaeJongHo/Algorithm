#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, M;
int map[1001][1001], temp[1000][1000];
bool visited[1000][1000];
vector<int> v;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void solve();
int dfs(int x, int y, int z);

int main() {
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - 48;
		}
	}
	solve();
	return 0;
}

void solve() {

	int z = 1;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && !visited[i][j]) {
				v.push_back(dfs(i, j, z));
				z += 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= N || nj < 0 || nj >= M)
						continue;
					s.insert(temp[ni][nj]);
				}
				for (auto k : s) map[i][j] += v[k];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j] % 10;
		cout << "\n";
	}
}

int dfs(int x, int y, int z) {
	temp[x][y] = z;
	int ret = 1;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (!visited[nx][ny] && !map[nx][ny])
			ret += dfs(nx, ny, z);
	}
	return ret;
}
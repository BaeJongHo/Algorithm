#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

int adjacency[201][201];
int visited[201];

int bfs(int start, int node, int des);

int main()
{
	int n = 7;
	int s = 3;
	int a = 4;
	int b = 1;
	vector<vector<int>> fares = { {5, 7, 9 }, { 4, 6, 4 }, { 3, 6, 1 }, { 3, 2, 3 }, { 2, 1, 6 }};

	int answer = 10000000;

	for (int i = 0; i < fares.size(); i++) {
		int temp_a = fares[i][0];
		int temp_b = fares[i][1];
		int dis = fares[i][2];

		adjacency[temp_a][temp_b] = dis;
		adjacency[temp_b][temp_a] = dis;
	}

	int temp = 0;
	for (int i = 1; i <= n; i++) {
		temp += bfs(s, n, i);
		temp += bfs(i, n, a);
		temp += bfs(i, n, b);

		if (temp >= 0)
			answer = min(answer, temp);
		temp = 0;
	}

	cout << answer;
	
	return 0;
}

int bfs(int start, int node, int des) {
	memset(visited, 1000000, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int loca;
		loca = q.front();

		q.pop();

		for (int i = 1; i <= node; i++) {
			if (adjacency[loca][i] == 0)
				continue;

			if (visited[i] < visited[loca] + adjacency[loca][i])
				continue;

			visited[i] = visited[loca] + adjacency[loca][i];
			q.push(i);
		}
	}

	return visited[des];
}
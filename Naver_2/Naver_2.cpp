#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int n = 9;
	vector<vector<int>> edges = { {0,2}, {2,1}, {2,4},  {3,5},  {5,4},  {5,7}, {7,6}, {6,8}, };
	vector<int> answer;

	int *result = new int[n];
	
	for (int i = 0; i < n; ++i)
		result[i] = 0;

	for (int i = 0; i < edges.size(); ++i) {
		int node1 = edges[i][0];
		int node2 = edges[i][1];

		result[node1] += 1;
		result[node2] += 1;
	}

	for (int i = 0; i < n; ++i) {
		if (result[i] > 2)
			answer.push_back(i);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
	
	return 0;
}

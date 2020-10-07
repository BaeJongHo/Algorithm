#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<vector<int>> teams;
vector<vector<int>> team(11, vector<int>(1));
int ans = 100000;
bool visited[11];
vector<int> participant;

void dfs(int cnt, int fare, int n, vector<int> sale);

int main()
{
	int answer = 0;

	vector<int> sales = { {14, 17, 15, 18, 19, 14, 13, 16, 28, 17 }};
	vector<vector<int>> links = { {10, 8 }, { 1, 9 }, { 9, 7 }, { 5, 4 }, { 1, 5 }, { 5, 10 }, { 10, 6 }, { 1, 3 }, { 10, 2 }};
	set<int> s;
	for (int i = 0; i < links.size(); i++) {
		int leader = links[i][0];
		s.insert(leader);
		for (int j = 1; j < links[i].size(); j++) {
			int member = links[i][j];
			team[leader].push_back(member);
		}
	}

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter) {
		vector<int> v;
		v.push_back(*iter);
		vector<int> temp_v = team[*iter];
		for (int i = 1; i < temp_v.size(); i++) {
			v.push_back(temp_v[i]);
		}
		teams.push_back(v);
	}

	dfs(0, 0, teams.size(), sales);

	answer = ans;

	return 0;
}

void dfs(int cnt, int fare, int n, vector<int> sale) {
	if (cnt >= n) {
		ans = min(ans, fare);
	}

	for (int i = 0; i < n; i++) {
		vector<int> members = teams[i];
		
		int checking = 0;
		for (int y = 0; y < participant.size(); y++) {
			for (int g = 0; g < members.size(); g++) {
				if (participant[y] == members[g])
					checking++;
			}
		}
		if (checking != 0)
			continue;
		
		for (int j = 0; j < members.size(); j++) {
			if (!visited[members[j]]) {
				visited[members[j]] = true;
				fare += sale[members[j] - 1];
				participant.push_back(members[j]);
				int check = 0;

			
				for (int k = 0; k < n; k++) {
					vector<int> temp_member = teams[k];
					for (int h = 0; h < temp_member.size(); h++) {
						if (members[j] == temp_member[h])
							check++;
					}
				}
				
				dfs(cnt + check, fare, n, sale);
				visited[members[j]] = false;
				fare -= sale[members[j] - 1];
				participant.pop_back();
			}
		}
	}
}
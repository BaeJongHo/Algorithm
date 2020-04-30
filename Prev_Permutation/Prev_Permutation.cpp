#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main()
{
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int idx = N - 1;
	//처음으로 내림차순이 나오는 부분을 찾음
	while (idx > 0 && v[idx - 1] < v[idx])
		idx--;

	//첫 순열인 경우 -1 출력
	if (idx == 0) {
		cout << -1;
		return 0;
	}

	int idx2 = N - 1;

	//v[idx-1] 보다 작은 v[idx2]의 idx2 찾고 swap
	while (v[idx - 1] < v[idx2])
		idx2--;
	swap(v[idx - 1], v[idx2]);

	idx2 = N - 1;

	//idx 이전 순열을 바꿔줌
	while (idx < idx2) {
		swap(v[idx], v[idx2]);
		idx++;
		idx2--;
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << " ";

	return 0;
}
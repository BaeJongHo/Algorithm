#include <iostream>
#define MAX_SIZE 2187

using namespace std;

int N;
int p[MAX_SIZE][MAX_SIZE];
int neg_cnt = 0, zero_cnt = 0, pos_cnt = 0;

void divide_paper(int x_start, int x_end, int y_start, int y_end);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> p[i][j];
		}
	}

	divide_paper(0, N, 0, N);

	cout << neg_cnt << "\n";
	cout << zero_cnt << "\n";
	cout << pos_cnt << "\n";

	return 0;
}

void divide_paper(int x_start, int x_end, int y_start, int y_end) {
	int check = 0;
	int first = p[x_start][y_start];

	if (x_end - x_start == 1 && y_end - y_start == 1) {
		if (p[x_start][y_start] == -1)
			neg_cnt++;
		else if (p[x_start][y_start] == 0)
			zero_cnt++;
		else if (p[x_start][y_start] == 1)
			pos_cnt++;
	}
	else {
		for (int i = x_start; i < x_end; i++) {
			for (int j = y_start; j < y_end; j++) {
				if (p[i][j] != first) {
					check++;
					break;
				}
			}
			if (check > 0)
				break;
		}

		if (check == 0) {
			if (first == -1)
				neg_cnt++;
			else if (first == 0)
				zero_cnt++;
			else if (first == 1)
				pos_cnt++;
		}
		else {
			divide_paper(x_start, x_start + (x_end - x_start) / 3, y_start, y_start + (y_end - y_start) / 3);
			divide_paper(x_start, x_start + (x_end - x_start) / 3, y_start + (y_end - y_start) / 3, y_end - (y_end - y_start) / 3);
			divide_paper(x_start, x_start + (x_end - x_start) / 3, y_end - (y_end - y_start) / 3, y_end);
			divide_paper(x_start + (x_end - x_start) / 3, x_end - (x_end - x_start) / 3, y_start, y_start + (y_end - y_start) / 3);
			divide_paper(x_start + (x_end - x_start) / 3, x_end - (x_end - x_start) / 3, y_start + (y_end - y_start) / 3, y_end - (y_end - y_start) / 3);
			divide_paper(x_start + (x_end - x_start) / 3, x_end - (x_end - x_start) / 3, y_end - (y_end - y_start) / 3, y_end);
			divide_paper(x_end - (x_end - x_start) / 3, x_end, y_start, y_start + (y_end - y_start) / 3);
			divide_paper(x_end - (x_end - x_start) / 3, x_end, y_start + (y_end - y_start) / 3, y_end - (y_end - y_start) / 3);
			divide_paper(x_end - (x_end - x_start) / 3, x_end, y_end - (y_end - y_start) / 3, y_end);
		}
	}
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{    
    vector<int> result;
    int n = 7;
    vector<int> p = { 6,2,1,0,2,4,3 };
    vector<int> c = { 3,6,6,2,3,7,6 };

    string answer = "";
    int stock = 0;
    int day = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int prod = p[i];
        int order = c[i];

        stock += prod;

        if (stock < order) {
            day += 2;
            if (day > 4) {
                n = i + 1;
                break;
            }
            continue;
        }

        if (day == 0) {
            ans = order * 100;
            stock -= order;
        }
        else {
            ans = order * (100 / day);
            stock -= order;
            day = 0;
        }

        result.push_back(ans);
    }
    float sum = 0;
    for (int i = 0; i < result.size(); ++i) {
        sum += result[i];
    }
    int int_part = sum / n;
    int float_part = (sum / n - int_part) * 100;

    answer += to_string(int_part);
    answer += '.';

    if (float_part == 0) {
        answer += to_string(0);
        answer += to_string(0);
    }
    else if (float_part < 10) {
        answer += to_string(float_part);
        answer += to_string(0);
    }
    else
        answer += to_string(float_part);

    cout << answer;

    return 0;
}

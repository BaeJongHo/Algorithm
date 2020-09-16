#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> res;
vector<string> temp;

vector<string> split(string str, char delimiter);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s;

    res = split(s, '-');

    int result = 0;
    for (int i = 0; i < res.size(); i++) {
        temp = split(res[i], '+');

        if (i == 0) {
            int temp_val = 0;
            for (int j = 0; j < temp.size(); j++) {
                temp_val += atoi(temp[j].c_str());
            }
            result += temp_val;
        }
        else {
            int temp_val = 0;
            for (int j = 0; j < temp.size(); j++) {
                temp_val += atoi(temp[j].c_str());
            }
            result -= temp_val;
        }
    }

    cout << result << endl;

    return 0;
}

vector<string> split(string str, char delimiter)
{
    uint64_t start_pos = 0;
    uint64_t search_pos = 0;
    vector<string> result;

    while (start_pos < str.size())
    {
        search_pos = str.find_first_of(delimiter, start_pos);
        string tmp_str;

        if (search_pos == string::npos)
        {
            search_pos = str.size();
            tmp_str = str.substr(start_pos, search_pos - start_pos);
            result.push_back(tmp_str);
            break;
        }
        tmp_str = str.substr(start_pos, search_pos - start_pos);
        result.push_back(tmp_str);
        start_pos = search_pos + 1;
    }

    return result;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter);

int main()
{
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    
    vector<int> answer;
    vector<string> query_word;
    vector<string> info_word;

    for (int i = 0; i < query.size(); i++) {
        string q = query[i];
        while (q.find(" and") >= 0) {
            int idx = q.find(" and");
            if (idx == -1)
                break;
            q.erase(idx, 4);
        }
        int cnt = 0;
        query_word = split(q, ' ');

        for (int j = 0; j < info.size(); j++) {
            int check = 0;
            string information = info[j];
            info_word = split(information, ' ');
            for (int k = 0; k < query_word.size(); k++) {
                if (query_word[k] == "-") {
                    check++;
                    continue;
                }

                if (k >= 0 && k < query_word.size() - 1) {
                    if (query_word[k] == info_word[k])
                        check++;
                }
                else {
                    if (atoi(query_word[k].c_str()) <= atoi(info_word[k].c_str()))
                        check++;
                }
            }
            if (check == 5)
                cnt++;
        }
        answer.push_back(cnt);
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

    vector<int> answer(queries.size(), 0);
    vector<int> range;

    for (int i = 0; i < queries.size(); i++) {
        string query_word = queries[i];
        
        for (int s = 0; s < query_word.size(); s++) {
            if (query_word[s] != '?') {
                range.push_back(s);
            }
        }

        for (int j = 0; j < words.size(); j++) {
            
            if (query_word.size() != words[j].size())
                continue;

            string query_temp = query_word.substr(range.front(), range.size());
            string word_temp = words[j].substr(range.front(), range.size());
            
            if (query_temp == word_temp) {
                answer[i] += 1;
            }
        }
        range.clear();
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}

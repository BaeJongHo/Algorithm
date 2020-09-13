#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int TrieNode = 26;

struct Trie {
    Trie* next[TrieNode];
    int count;
    bool term;

    Trie() : term(false), count(1) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < TrieNode; i++) {
            if (next[i])
                delete next[i];
        }
    }

    void insert(const char* c) {
        if (*c == '\0')
            term = true;
        else {
            int curr = *c - 'a';
            if (next[curr] == nullptr)
                next[curr] = new Trie();
            else
                next[curr]->count++;
            next[curr]->insert(c + 1);
        }
    }

    int find(const char* c) {
        int curr = *c - 'a';

        if (*c == '?') {
            int tmp = 0;
            for (int k = 0; k < TrieNode; k++) {
                if (next[k] != nullptr)
                    tmp += next[k]->count;
            }
            return tmp;
        }
        if (next[curr] == nullptr)
            return 0;
        if (*(c + 1) == '?')
            return next[curr]->count;

        return next[curr]->find(c + 1);
    }
};

Trie* root[10001];
Trie* reroot[10001];

int main()
{
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

    vector<int> answer(queries.size(), 0);

    for (int i = 0; i < words.size(); i++) {
        string a = words[i];
        if (root[a.size()] == nullptr)
            root[a.size()] = new Trie();
        root[a.size()]->insert(a.c_str());

        string re_a = words[i];
        reverse(re_a.begin(), re_a.end());

        if (reroot[re_a.size()] == nullptr)
            reroot[re_a.size()] = new Trie();
        reroot[re_a.size()]->insert(re_a.c_str());
    }

    for (int i = 0; i < queries.size(); i++) {
        string a = queries[i];

        if (a[a.size() - 1] == '?') {
            if (root[a.size()] == nullptr)
                continue;
            else
                answer[i] = root[a.size()]->find(a.c_str());
        }
        else {
            string re = a;
            reverse(re.begin(), re.end());
            if (reroot[re.size()] == nullptr)
                continue;
            else
                answer[i] = reroot[re.size()]->find(re.c_str());
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}

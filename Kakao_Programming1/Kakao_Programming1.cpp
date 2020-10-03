#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    string new_id = "abcdefghijklmn.p";

    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    for (int i = 0; i < new_id.size();) {
        if ((new_id[i] >= 97 && new_id[i] <= 122) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= 48 && new_id[i] <= 57)) {
            i++;
            continue;
        }
        new_id.erase(i, 1);
    }

    for (int i = 0; i < new_id.size() - 1;) {
        if (new_id[i] == '.' && new_id[i] == new_id[i + 1]) {
            new_id.erase(i, 1);
            continue;
        }
        i++;
    }

    if (new_id[0] == '.')
        new_id.erase(0, 1);
    if (new_id != "") {
        if (new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.size() - 1, 1);
    }

    if (new_id == "")
        new_id.push_back('a');

    if (new_id.size() >= 16)
        new_id.erase(15, new_id.size() - 15);

    if (new_id.size() <= 2) {
        while (new_id.size() != 3) {
            char a = new_id[new_id.size() - 1];
            new_id.push_back(a);
        }
    }

    if (new_id != "") {
        if (new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.size() - 1, 1);
    }

    answer += new_id;

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    return 0;
}

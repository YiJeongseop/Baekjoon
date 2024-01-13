#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;

    cin >> s;
    v.push_back(s);
    for (int i = 0; i < s.size(); i++) {
        string tmp = "";
        for (int j = i + 1; j < s.size(); j++) {
            tmp += s[j];
        }
        if (tmp == "") continue;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (auto& i : v) {
        cout << i << '\n';
    }

    return 0;
}
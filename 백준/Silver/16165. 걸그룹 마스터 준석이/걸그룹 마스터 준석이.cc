#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> m;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string group_name;
        cin >> group_name;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) {
            string idol_name;
            cin >> idol_name;
            m[idol_name] = group_name;
        }
    }

    vector<pair<string, string>> v(m.begin(), m.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        int num;
        cin >> num;
        if (num == 1) cout << m[str] << '\n';
        else {
            for (auto j : v) {
                if (j.second == str) cout << j.first << '\n';
            }
        }
    }

    return 0;
}
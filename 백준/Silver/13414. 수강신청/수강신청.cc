#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        string str;
        cin >> str;
        if (m.find(str) == m.end()) {
            m[str] = i;
        }
        else {
            m.erase(str);
            m[str] = i;
        }
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int target = min(K, (int)m.size());
    int cnt = 0;
    for (auto i : v) {
        cnt++;
        cout << i.first << '\n';
        if (cnt == target) break;
    }

    return 0;
}
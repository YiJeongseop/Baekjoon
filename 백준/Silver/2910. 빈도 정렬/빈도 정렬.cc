#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N, C, tmp;
int arr[1000];
map<int, int> m, m2;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return m[a.first] < m[b.first];
    }
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr[i] = tmp;
        if (m.find(tmp) == m.end()) {
            m.insert({ tmp, i });
            m2.insert({ tmp, 1 });
        }
        else {
            m2[tmp]++;
        }
    }

    vector<pair<int, int>> v(m2.begin(), m2.end());

    sort(v.begin(), v.end(), cmp);

    for (auto& i : v) {
        for (int j = 0; j < i.second; j++) {
            cout << i.first << " ";
        }
    }

    return 0;
}
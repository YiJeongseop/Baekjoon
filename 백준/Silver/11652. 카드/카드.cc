#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;

bool cmp(const pair<long long, int>& a, const pair<long long, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    map<long long, int> m;

    long long tmp;
    while (N--) {
        cin >> tmp;
        if (m.find(tmp) != m.end()) {
            m[tmp]++;
        }
        else {
            m.insert({ tmp, 1 });
        }
    }
    vector<pair<long long, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    cout << v[v.size() - 1].first << '\n';

    return 0;
}
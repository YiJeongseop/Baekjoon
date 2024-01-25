#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>

using namespace std;
using ll = long long;

vector<pair<int, int>> jewelry;
multiset<int> bag;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, tmp1, tmp2;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        jewelry.push_back({ tmp1, tmp2 });
    }

    sort(jewelry.begin(), jewelry.end(), cmp);

    for (int i = 0; i < K; i++) {
        cin >> tmp1;
        bag.insert(tmp1);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        auto target = bag.lower_bound(jewelry[i].first);
        if (target == bag.end()) continue;
        ans += jewelry[i].second;
        bag.erase(target);
    }

    cout << ans;

    return 0;
}
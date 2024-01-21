#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;
using ll = long long;
ll tree[1000000];
ll N, M;

bool solve(ll num) {
    ll cur = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] > num) cur += tree[i] - num;
    }
    return cur >= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> tree[i];

    ll st = 1;
    ll en = *max_element(tree, tree + N);
    while (st <= en) {
        ll mid = (st + en) / 2;
        if (solve(mid)) st = mid + 1;
        else en = mid - 1;
    }
    
    cout << st - 1;

    return 0;
}
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

ll budget[1000000];
ll N, M;

bool solve(ll num) {
    ll cur = 0;
    for (int i = 0; i < N; i++) {
        if (budget[i] < num) cur += budget[i];
        else cur += num;
    }
    return cur <= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> budget[i];
        sum += budget[i];
    }
    cin >> M;

    if (sum <= M) {
        cout << *max_element(budget, budget + N);
        return 0;
    }

    ll st = 1;
    ll en = *max_element(budget, budget + N);
    while (st <= en) {
        ll mid = (st + en) / 2;
        if (solve(mid)) st = mid + 1;
        else en = mid - 1;
    }
    
    cout << st - 1;

    return 0;
}
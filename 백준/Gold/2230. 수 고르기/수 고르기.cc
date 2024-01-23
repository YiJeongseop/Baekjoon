#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;
using ll = long long;

ll arr[100000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, ans = LLONG_MAX;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(arr, arr + N, arr[i] + M) - arr;
        if (idx >= N) continue;
        ans = min(ans, arr[idx] - arr[i]);
    }

    cout << ans;

    return 0;
}
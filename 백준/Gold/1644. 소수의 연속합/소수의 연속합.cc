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
bool state[4000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    fill(state, state + N + 1, true);
    state[1] = false;

    for (ll i = 2; i * i <= N; i++) {
        if (!state[i]) continue;
        for (ll j = i + i; j <= N; j += i) {
            if (!state[j])continue;
            state[j] = false;
        }
    }

    vector<ll> prime;
    for (ll i = 1; i <= N; i++) {
        if (state[i]) prime.push_back(i);
    }

    if (prime.size() == 0) {
        cout << 0;
        return 0;
    }

    ll sum = prime[0];
    ll en = 0, ans = 0;
    for (ll st = 0; st < prime.size(); st++) {
        while (en < prime.size() && sum < N) {
            en++;
            if (en != prime.size()) sum += prime[en];
        }
        if (en == prime.size()) break;
        if (sum == N) ans++;
        sum -= prime[st];
    }

    cout << ans;

    return 0;
}
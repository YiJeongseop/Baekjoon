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

int A[4000], B[4000], C[4000], D[4000];
vector<ll> ab, cd;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(A[i] + B[j]);
            cd.push_back(C[i] + D[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    ll ans = 0;
    for (int i = 0; i < ab.size(); i++) {
        //cout << "ab[" << i << "] : " << ab[i] << '\n';
        ll up = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        ll lo = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        ans += up - lo;
        //cout << "cd[" << up - 1 << "] : " << cd[up - 1] << ", cd[" << up << "] : " << cd[up] << '\n';
        //cout << "cd[" << lo - 1 << "] : " << cd[lo - 1] << ", cd[" << lo << "] : " << cd[lo] << '\n';
    }

    cout << ans;
    
    return 0;
}
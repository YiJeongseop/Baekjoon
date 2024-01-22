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

ll arr1[1000], arr2[1000];
ll d1[1000][1000], d2[1000][1000];
vector<int> v1, v2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m;
    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> arr2[i];

    for (int i = 0; i < n; i++) {
        d1[i][i] = arr1[i];
        v1.push_back(d1[i][i]);
    }
    for (int i = 0; i < m; i++) {
        d2[i][i] = arr2[i];
        v2.push_back(d2[i][i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) continue;
            d1[i][j] = d1[i][j - 1] + arr1[j];
            v1.push_back(d1[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (i == j) continue;
            d2[i][j] = d2[i][j - 1] + arr2[j];
            v2.push_back(d2[i][j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    //for (int i = 0; i < v1.size(); i++) {
    //    cout << v1[i] << " ";
    //}
    //cout << '\n';
    //for (int i = 0; i < v2.size(); i++) {
    //    cout << v2[i] << " ";
    //}
    //cout << '\n';

    ll ans = 0;
    for (int i = 0; i < v1.size(); i++) {
        int tmp = T - v1[i];
        //cout << "tmp : " << tmp << ", upper_bound: " << upper_bound(v2.begin(), v2.end(), tmp) - v2.begin() << ", lower_bound: " << lower_bound(v2.begin(), v2.end(), tmp) - v2.begin() << '\n';
        ans += upper_bound(v2.begin(), v2.end(), tmp) - lower_bound(v2.begin(), v2.end(), tmp);
    }
    cout << ans;

    return 0;
}
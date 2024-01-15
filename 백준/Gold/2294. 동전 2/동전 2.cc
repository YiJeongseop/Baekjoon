#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int n, k;
int arr[101];
int d[10001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    fill(d, d + k + 1, INT_MAX - 100000);
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            d[j] = min(d[j], d[j - arr[i]] + 1);
            //cout << "d[" << j << "] : " << d[j] << '\n';
        }
    }

    if (d[k] == INT_MAX - 100000) cout << -1;
    else cout << d[k];

    return 0;
}
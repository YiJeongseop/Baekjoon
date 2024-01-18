#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, k, l;
    cin >> N >> k >> l;

    int ans = 1;
    while (ans <= N) {
        if (abs(k - l) == 1) {
            if ((k % 2 == 1 && k + 1 == l) || (l % 2 == 1 && l + 1 == k)) {
                cout << ans;
                return 0;
            }
        }

        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k++;
            k /= 2;
        }

        if (l % 2 == 0) {
            l /= 2;
        }
        else {
            l++;
            l /= 2;
        }

        ans++;
    }
    cout << -1;

    return 0;
}
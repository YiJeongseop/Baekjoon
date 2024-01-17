#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int L, P, V;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> P >> V;
    int cnt = 1;

    while (L != 0 && P != 0 && V != 0) {
        int ans = 0;
        ans += L * (V / P);
        if (V % P >= L) {
            ans += L;
        }
        else {
            ans += V % P;
        }
        cout << "Case " << cnt << ": " << ans << '\n';
        cnt++;
        cin >> L >> P >> V;
    }

    return 0;
}
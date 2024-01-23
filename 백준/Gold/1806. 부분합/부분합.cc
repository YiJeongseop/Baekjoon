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

int arr[100000];
bool debug_flag = false;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S, ans = INT_MAX;
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    bool flag = false;
    int en = -1, sum = 0;
    for (int st = 0; st < N; st++) {
        while (sum < S && en != N) {
            en++;
            if (en == N)break;
            sum += arr[en];
        }
        if (debug_flag) cout << "st : " << st << ", en : " << en << ", sum : " << sum << '\n';
        if (sum >= S) ans = min(ans, en - st + 1);
        if (debug_flag) cout << "ans : " << ans << '\n';
        sum -= arr[st];
    }

    if (ans == INT_MAX) cout << 0;
    else cout << ans;

    return 0;
}
#include <iostream>

using namespace std;

int T;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n, ans = 1;
        cin >> n;

        for (int i = 2; i <= n; i++) {
            int tmp = 0;
            for (int j = 2; j <= n / 2; j++) {
                if (i % j == 0) {
                    if (j * j == i) tmp++;
                    else tmp += 2;
                }
            }
            if (tmp % 2 == 1) {
                // cout << "i : " << i << '\n';
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int n;
long long d[2000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1000000] = 0; d[1000001] = 1;
    int ans = 0;
    if (n > 0) {
        for (int i = 1000002; i <= 1000000 + n; i++) {
            d[i] = (d[i - 1] + d[i - 2]) % 1000000000;
            if (i == 1000000 + n) {
                if (d[i] == 0) ans = 0;
                else if (d[i] > 0) ans = 1;
            }
        }
    }
    else {
        for(int i = 999999; i >= 1000000 + n; i--){
            if (i == 1000000 + n) {
                if (d[i + 2] - d[i + 1] < 0) ans = -1;
                else if (d[i + 2] - d[i + 1] == 0) ans = 0;
                else ans = 1;
            }
            d[i] = (d[i + 2] - d[i + 1]) % 1000000000;
            //cout << "d[" << i << "] 값 : " << d[i] << '\n';
        }
    }

    if (n == 1) {
        cout << 1 << '\n' << 1;
        return 0;
    }

    if (ans == -1) {
        cout << ans << '\n' << (d[1000000 + n] * -1) % 1000000000;
    }
    else {
        cout << ans << '\n' << d[1000000 + n] % 1000000000;
    }

    return 0;
}
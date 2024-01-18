#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;


bool check(int a) {
    int tmp = static_cast<int>(sqrt(a) + 0.5);

    return tmp * tmp == a;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int x, y;
        cin >> x >> y;
        int dis = y - x;
        if (dis == 1) {
            cout << 1 << '\n';
            continue;
        }
        else if (dis == 2) {
            cout << 2 << '\n';
            continue;
        }
        else if (dis == 3) {
            cout << 3 << '\n';
            continue;
        }
        else if (dis == 4) {
            cout << 3 << '\n';
            continue;
        }
        else {
            int tmp = dis;
            while (true) {
                if (check(tmp)) {
                    break;
                }
                tmp--;
            }
            if (tmp == dis) {
                cout << (int)sqrt(tmp) * 2 - 1 << '\n';
                continue;
            }
            int nxt_val = pow(((int)sqrt(tmp) + 1), 2);
            int tmp2 = (nxt_val - tmp) / 2;
            // cout << tmp << ", " << nxt_val << ", " << tmp2 << '\n';
            if (tmp + tmp2 >= dis) cout << (int)sqrt(tmp) * 2 << '\n';
            else cout << (int)sqrt(tmp) * 2 + 1 << '\n';
        }
    }

    return 0;
}
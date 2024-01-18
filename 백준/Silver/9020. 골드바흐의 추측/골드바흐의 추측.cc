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

    int T, N;
    cin >> T;

    vector<bool> v(10002, true);
    v[1] = false;
    for (int i = 2; i * i <= 10001; i++) {
        if (!v[i])continue;
        for (int j = i + i; j <= 10001; j += i) {
            v[j] = false;
        }
    }

    while (T--) {
        cin >> N;
        for (int i = N / 2; i > 0; i--) {
            if (v[i] && v[N - i]) {
                cout << i << " " << N - i << '\n';
                break;
            }
        }
    }

    return 0;
}
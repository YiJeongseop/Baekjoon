#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int d[16];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    d[0] = 0;
    int T, P, tmp2 = 0;
    for (int i = 1; i <= N; i++) {
        cin >> T >> P;
        if (i + T - 1 > N) continue;
        for (int j = i - 1; j > 0; j--) {
            if (j == 0) continue;
            tmp2 = max(tmp2, d[j]);
        }
        d[i + T - 1] = max(d[i + T - 1], tmp2 + P);
    }

    int tmp = -1;
    for (int i = 1; i <= N; i++) {
        tmp = max(tmp, d[i]);
    }
    cout << tmp;

    return 0;
}
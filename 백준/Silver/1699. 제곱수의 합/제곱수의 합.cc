#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(d, d + N + 1, INT_MAX);
    d[1] = 1; d[2] = 2; d[3] = 3; d[4] = 1; d[5] = 2;

    for (int i = 6; i <= N; i++) {
        int tmp = floor(sqrt(i));
        if (i == tmp * tmp) {
            d[i] = 1;
            continue;
        }
        //cout << "tmp는 " << tmp << "입니다. \n";
        for (int j = tmp; j > 0; j--) {
            d[i] = min(d[i], d[j * j] + d[i - j * j]);
            //cout << "d[" << j * j << "] + d[" << i - j * j << "] : " << d[j * j] + d[i - j * j] << '\n';
        }
        //cout << "d[" << tmp * tmp <<"] : " << d[tmp * tmp] << ", d[" << i - tmp * tmp << "] : " << d[i - tmp * tmp] << '\n';
    }

    cout << d[N];

    return 0;
}
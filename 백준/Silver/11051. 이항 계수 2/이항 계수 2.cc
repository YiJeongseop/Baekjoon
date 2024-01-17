#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N, K;
int d[1001][1001];

int func(int n, int k) {
    if (d[n][k] != 0) return d[n][k];
    if (k == 0 || n == k) {
        d[n][k] = 1;
        return 1;
    }
    d[n][k] = (func(n - 1, k) + func(n - 1, k - 1)) % 10007;
    return d[n][k] % 10007;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    cout << func(N, K);

    return 0;
}
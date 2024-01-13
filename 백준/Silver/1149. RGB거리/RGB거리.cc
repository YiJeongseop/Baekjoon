#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int cost[1001][4];
int d[1001][4];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i][1] >> cost[i][2] >> cost[i][3];
    }

    d[1][1] = cost[1][1]; d[1][2] = cost[1][2]; d[1][3] = cost[1][3];
    d[2][1] = cost[2][1] + min(d[1][2], d[1][3]); d[2][2] = cost[2][2] + min(d[1][1], d[1][3]); d[2][3] = cost[2][3] + min(d[1][1], d[1][2]);
    for (int i = 3; i <= N; i++) {
        d[i][1] = cost[i][1] + min(d[i - 1][2], d[i - 1][3]);
        d[i][2] = cost[i][2] + min(d[i - 1][1], d[i - 1][3]);
        d[i][3] = cost[i][3] + min(d[i - 1][1], d[i - 1][2]);
    }

    int tmp = min(d[N][1], d[N][2]);
    int ans = min(tmp, d[N][3]);
    cout << ans;

    return 0;
}
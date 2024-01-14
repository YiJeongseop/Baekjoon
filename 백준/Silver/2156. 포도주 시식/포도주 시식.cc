#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int n;
int arr[10001];
int d[10001][3]; // 마시지 않았을 때, 연속 1잔, 연속 2잔

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    d[1][1] = arr[1];
    int ans = arr[1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = max({ d[i - 1][2], d[i - 1][1], d[i - 1][0] });
        d[i][1] = d[i - 1][0] + arr[i];
        d[i][2] = d[i - 1][1] + arr[i];
        ans = max({ ans, d[i][0], d[i][1], d[i][2] });
    }

    cout << ans;

    return 0;
}
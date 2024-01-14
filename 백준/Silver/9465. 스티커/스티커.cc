#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int T, cnt;
int arr[100001][2];
int d[100001][2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            cin >> arr[i + 1][0];
        }
        for (int i = 0; i < cnt; i++) {
            cin >> arr[i + 1][1];
        }

        d[1][0] = arr[1][0]; d[1][1] = arr[1][1];
        for (int i = 2; i <= cnt; i++) {
            d[i][0] = max({ d[i - 1][1] , d[i - 2][1], d[i - 2][0] }) + arr[i][0];
            d[i][1] = max({ d[i - 1][0] , d[i - 2][1], d[i - 2][0] }) + arr[i][1];
        }

        cout << max(d[cnt][0], d[cnt][1]) << '\n';
    }

    return 0;
}
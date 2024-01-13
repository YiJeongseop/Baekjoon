#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int arr[301];
int d[301][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    d[1][1] = arr[1]; d[2][1] = arr[2]; d[2][2] = arr[1] + arr[2];
    d[3][1] = arr[1] + arr[3]; d[3][2] = arr[2] + arr[3];
    for (int i = 4; i <= N; i++) {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + arr[i];
        d[i][2] = d[i - 1][1] + arr[i];
    }

    cout << max(d[N][1], d[N][2]);

    return 0;
}
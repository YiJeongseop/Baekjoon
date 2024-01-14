#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N, n, k = 1;
int graph[100001][4];
int d[100001][4];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N != 0) {
        for (int i = 1; i <= N; i++) {
            cin >> graph[i][1] >> graph[i][2] >> graph[i][3];
        }
        d[1][2] = graph[1][2]; d[1][3] = d[1][2] + graph[1][3];
        d[2][1] = d[1][2] + graph[2][1]; d[2][2] = min({ d[1][2], d[2][1], d[1][3] }) + graph[2][2];
        d[2][3] = min({ d[1][2], d[1][3], d[2][2] }) + graph[2][3];
        n = d[2][2];
        for (int i = 3; i <= N; i++) {
            d[i][1] = min(d[i - 1][1], d[i - 1][2]) + graph[i][1];
            d[i][2] = min({ d[i][1], d[i - 1][1], d[i - 1][2], d[i - 1][3] }) + graph[i][2];
            d[i][3] = min({ d[i][2], d[i - 1][2], d[i - 1][3] }) + graph[i][3];
        }
        if (N > 2) {
            n = d[N][2];
        }

        cout << k << ". " << n << '\n';

        k++;
        cin >> N;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N, M;
int arr[2001];
int d[2001][2001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        d[i][i] = 1;
    }

    for (int i = N; i > 0; i--) {
        for (int j = i + 1; j <= N; j++) {
            if (j == i + 1 && arr[j] == arr[i]) d[i][j] = 1;
            else if (j == i + 1 && arr[j] != arr[i]) continue;
            else {
                if (arr[j] == arr[i]) {
                    if (d[i + 1][j - 1] == 1)d[i][j] = 1;
                    else continue;
                }
                else {
                    continue;
                }
            }
        }
    }

    int S, E;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << d[S][E] << '\n';
    }

    return 0;
}
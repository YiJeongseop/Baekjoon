#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int P[1001];
int d[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i + 1];

    d[0] = 0;  d[1] = P[1];
    for (int i = 2; i <= N; i++) {
        d[i] = P[i];
        for (int j = i - 1; j > 0; j--) {
            d[i] = max(d[i], d[i - j] + d[j]);
        }
    }

    cout << d[N];

    return 0;
}
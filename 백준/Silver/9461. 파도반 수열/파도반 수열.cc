#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int T, N;
long long d[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
    d[6] = 3; d[7] = 4; d[8] = 5; d[9] = 7; d[10] = 9;

    for (int i = 11; i <= 100; i++) {
        d[i] = d[i - 1] + d[i - 5];
    }

    while (T--) {
        cin >> N;
        cout << d[N] << '\n';
    }

    return 0;
}
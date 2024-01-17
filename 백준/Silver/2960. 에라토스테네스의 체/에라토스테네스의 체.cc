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
bool table[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    fill(table + 1, table + N + 1, true);

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (!table[i]) continue;
        for (int j = i; j <= N; j += i) {
            if (!table[j]) continue;
            table[j] = false;
            cnt++;
            if (cnt == K) {
                cout << j;
                return 0;
            }
        }
        
    }

    return 0;
}
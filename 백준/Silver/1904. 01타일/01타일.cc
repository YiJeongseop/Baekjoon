#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int d[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    d[1] = 1; d[2] = 2; d[3] = 3;
    for (int i = 4; i <= N; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % 15746;
    }
    
    cout << d[N];

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;
int snack[1000001];
int M, N;

bool solve(int num) {
    int cur = 0;
    for (int i = 0; i < N; i++) cur += snack[i] / num;
    return cur >= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; i++) cin >> snack[i];

    int st = 1;
    int en = *max_element(snack, snack + N);
    while (st <= en) {
        int mid = (st + en) / 2;
        // cout << "st : " << st << ", mid : " << mid << ", en : " << en << '\n';
        if (solve(mid)) st = mid + 1;
        else en = mid - 1;
    }
    
    cout << st - 1;

    return 0;
}
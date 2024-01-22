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

int house[200000];
int N, C, cnt = 1, ans = 0;

int solve(int leng) {
    cnt = 1;
    int pre_house = house[0];
    for (int i = 1; i < N; i++) {
        if (house[i] - pre_house < leng) continue;
        else {
            pre_house = house[i];
            cnt++;
        }
    }
    if (cnt >= C) ans = max(ans, leng);
    //cout << "leng : " << leng << ", cnt : " << cnt << '\n';
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> house[i];
    sort(house, house + N);

    //cout << "house 배열" << '\n';
    //for (int i = 0; i < N; i++)
    //    cout << house[i] << " ";
    //cout << '\n';

    int st = 1;
    int en = house[N - 1] - house[0];
    while (st <= en) {
        int mid = (st + en) / 2;
        //cout << "st : " << st << ", mid : " << mid << ", en : " << en << '\n';
        if (solve(mid) >= C) st = mid + 1;
        else en = mid - 1;
    }

    cout << ans;

    return 0;
}
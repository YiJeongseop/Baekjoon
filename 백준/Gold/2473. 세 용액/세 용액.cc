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
using ll = long long;
ll arr[5000];
ll ans_val = LLONG_MAX;
vector<ll> ans;

void renew_ans(ll val, ll i, ll j, ll st) {
    ans_val = val;
    ans.clear();
    ans.push_back(i);
    ans.push_back(j);
    ans.push_back(st);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    //cout << "정렬된 arr" << '\n';
    //for (int i = 0; i < N; i++) {
    //    cout << arr[i] << " ";
    //}
    //cout << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll target = -(arr[i] + arr[j]);
            ll st = 0;
            ll en = N - 1;
            while (st < en) {
                ll mid = (st + en) / 2;
                if (arr[mid] > target) en = mid - 1;
                else if (arr[mid] < target) st = mid + 1;
                else {
                    st = mid;
                    break;
                }
            }
            if (st != 0 && abs(target - arr[st]) > abs(target - arr[st - 1])) st--;
            //cout << "arr[" << i << "] : " << arr[i] << ", arr[" << j << "] : " << arr[j] << '\n';
            //cout << "가장 가까운 수는 arr[" << st << "] : " << arr[st] << '\n';
            if (st != i && st != j) {
                if (ans_val > abs(target - arr[st])) renew_ans(abs(target - arr[st]), i, j, st);
            }
            else {
                if (st == 0) {
                    while (st == i || st == j) st++;
                    if (ans_val > abs(target - arr[st])) renew_ans(abs(target - arr[st]), i, j, st);
                }
                else if (st == N - 1) {
                    while (st == i || st == j) st--;
                    if (ans_val > abs(target - arr[st])) renew_ans(abs(target - arr[st]), i, j, st);
                }
                else if (st == N - 2) {
                    if (i == N - 1 || j == N - 1) {
                        if (ans_val > abs(target - arr[st - 1])) renew_ans(abs(target - arr[st - 1]), i, j, st - 1);
                    }
                }
                else if (st == 1) {
                    if (i == 0 || j == 0) {
                        if (ans_val > abs(target - arr[st + 1])) renew_ans(abs(target - arr[st + 1]), i, j, st + 1);
                    }
                }
                else {
                    ll tmp1 = st, tmp2 = st;
                    while (tmp1 == i || tmp1 == j) tmp1++;
                    while (tmp2 == i || tmp2 == j) tmp2--;
                    if (ans_val > abs(target - arr[tmp1])) renew_ans(abs(target - arr[tmp1]), i, j, tmp1);
                    if (ans_val > abs(target - arr[tmp2])) renew_ans(abs(target - arr[tmp2]), i, j, tmp2);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << arr[ans[0]] << " " << arr[ans[1]] << " " << arr[ans[2]];

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N;
int arr[501];
deque<int> dq;

bool ans_check() {
    for (int i = 1; i <= N; i++)
        if (arr[i] != dq[i - 1]) return false;
    return true;
}

void reset_dq() {
    dq.clear();
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int p = 0, q = 0;
    for (int i = 1; i < N; i++) {
        int tmp = arr[i + 1] - arr[i];
        if (tmp == 1 || tmp == -1 || tmp == 1 - N || tmp == N - 1) continue;
        p = i + 1;
        break;
    }
    for (int i = 1; i < N; i++) {
        int tmp = arr[i + 1] - arr[i];
        if (tmp == 1 || tmp == -1 || tmp == 1 - N || tmp == N - 1) continue;
        q = i;
    }

    if (p == 0 && q == 0) {
        if (arr[1] == N) {
            cout << 1 << '\n' << 1 << " " << N << '\n' << 1;
            return 0;
        }
        else {
            for (int i = 2; i <= N; i++) {
                if (arr[i] == N) {
                    cout << 1 << '\n' << 1 << " " << N << '\n' << N + 2 - i;
                    return 0;
                }
            }
        }
    }
    else if (p > q) {
        q = p - 1;
        p = 1;
    }

    int chk = 0;
    for (int i = p; i < q; i++) {
        int tmp = arr[i + 1] - arr[i];
        if (tmp == 1 || tmp == 1 - N) chk++;
    }
    if (chk == q - p) {
        int tmp2 = p;
        p = q;
        q = tmp2;
        p++;
        q--;
    }

    vector<int> v;
    vector<int> v2;
    if (p > q) {
        for (int i = p; i <= N; i++) {
            v.push_back(arr[i]);
            v2.push_back(arr[i]);
        }
        for (int i = 1; i <= q; i++) {
            v.push_back(arr[i]);
            v2.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        int tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] + 1 != v[i + 1]) {
                tmp1 = i;
                tmp2 = i + 1;
                break;
            }
        }
        bool flag = false;
        int flag_var1, flag_var2;
        int k1 = v[tmp1]; int k2 = v[tmp2];
        if (tmp1 == 0 && tmp2 == 0) {
            flag = true;
            flag_var1 = v[0];
            flag_var2 = v[v.size() - 1];
            k1 = 1;
            k2 = N;
        }
        for (int k = k1; k < k2; k++) {
            if (flag) {
                if (k >= flag_var1 && k < flag_var2) continue;
            }
            reset_dq();
            for (int i = 1; i <= k; i++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            int ans_p, ans_q;
            for (int i = 0; i < dq.size(); i++) {
                if (dq[i] == v[tmp2]) {
                    for (int j = 0; j < v2.size(); j++) {
                        dq[i + j] = v2[j];
                    }
                    ans_p = i + 1; ans_q = i + v2.size();
                    break;
                }
            }
            for (int i = 1; i < N; i++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                if (ans_check()) {
                    cout << k << '\n' << ans_p << " " << ans_q << '\n' << i;
                    return 0;
                }
            }
        }
    }
    else {
        for (int i = p; i <= q; i++) {
            v.push_back(arr[i]);
            v2.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        int tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] + 1 != v[i + 1]) {
                tmp1 = i;
                tmp2 = i + 1;
                break;
            }
        }
        bool flag = false;
        int flag_var1, flag_var2;
        int k1 = v[tmp1]; int k2 = v[tmp2];
        if (tmp1 == 0 && tmp2 == 0) {
            flag = true;
            flag_var1 = v[0];
            flag_var2 = v[v.size() - 1];
            k1 = 1;
            k2 = N;
        }
        for (int k = k1; k < k2; k++) {
            if (flag) {
                if (k >= flag_var1 && k < flag_var2) continue;
            }
            reset_dq();
            for (int i = 1; i <= k; i++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            int ans_p, ans_q;
            for (int i = 0; i < dq.size(); i++) {
                if (dq[i] == v[tmp2]) {
                    for (int j = 0; j < v2.size(); j++) {
                        dq[i + j] = v2[j];
                    }
                    ans_p = i + 1; ans_q = i + v2.size();
                    break;
                }
            }
            for (int i = 1; i < N; i++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                if (ans_check()) {
                    cout << k << '\n' << ans_p << " " << ans_q << '\n' << i;
                    return 0;
                }
            }
        }
    }

    return 0;
}
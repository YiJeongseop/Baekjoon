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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool* arr = new bool[10001];
    fill(arr, arr + 10000, true);
    arr[1] = false;
    for (int i = 2; i * i <= 10000; i++) {
        if (!arr[i]) continue;
        for (int j = i + i; j <= 10000; j+= i) {
            if (!arr[j]) continue;
            arr[j] = false;
        }
    }

    int T, A, B;
    bool check[10001] = { false, };
    cin >> T;
    while (T--) {
        cin >> A >> B;
        fill(check, check + 10000, false);
        queue<pair<int, int>> q;
        q.push({A, 0});
        check[A] = true;
        bool flag = false;
        while (!q.empty()) {
            auto cur = q.front();
            //cout << "cur.first : " << cur.first << ", cur.second : " << cur.second << '\n';
            q.pop();
            if (cur.first == B) {
                cout << cur.second << '\n';
                flag = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                string tmp = to_string(cur.first);
                string tmp2 = tmp;
                for (int j = 0; j <= 9; j++) {
                    if (i == 0 && j == 0) continue;
                    if (tmp[i] - '0' == j) continue;
                    tmp2[i] = j + '0';
                    //cout << "tmp2 : " << tmp2 << '\n';
                    int tmp3 = stoi(tmp2);
                    //cout << "tmp3 : " << tmp3 << '\n';
                    //cout << "check[tmp3] " << check[tmp3] << ", arr[tmp3] : " << arr[tmp3] << '\n';
                    if (check[tmp3] || !arr[tmp3]) continue;
                    //cout << "q에 " << tmp3 << ", " << cur.second + 1 << "이 들어갑니다. " << '\n';
                    q.push({ tmp3, cur.second + 1 });
                    check[tmp3] = true;
                }
            }
        }
        if (!flag) cout << "Impossible" << '\n';
    }

    delete[] arr;

    return 0;
}
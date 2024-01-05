#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int r, c, k, y_len = 3, x_len = 3;
int arr[101][101];
int num[101];
bool check[101];

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

//void debug_print() {
//    cout << '\n';
//    for (int y = 1; y <= y_len; y++) {
//        for (int x = 1; x <= x_len; x++) {
//            cout << arr[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int y = 1; y < 4; y++) {
        for (int x = 1; x < 4; x++) {
            cin >> arr[y][x];
        }
    }

    int ans = 0;
    while (arr[r][c] != k) {
        if (ans == 101) {
            cout << -1;
            return 0;
        }
        ans++;
        if (y_len >= x_len) {
            int x_len_max = 0;
            for (int y = 1; y <= y_len; y++) {
                fill(num, num + 101, 0);
                fill(check, check + 101, false);
                vector<pair<int, int>> v;
                for (int x = 1; x <= x_len; x++) {
                    if (!arr[y][x]) continue;
                    num[arr[y][x]]++;
                }
                for (int x = 1; x <= x_len; x++) {
                    if (!arr[y][x] || check[arr[y][x]]) continue;
                    v.push_back({ arr[y][x], num[arr[y][x]] });
                    check[arr[y][x]] = true;
                }
                sort(v.begin(), v.end(), comparePairs);
                if (v.size() * 2 < x_len) {
                    for (int i = v.size() * 2 + 1; i <= x_len; i++) {
                        arr[y][i] = 0;
                    }
                }
                x_len_max = max(x_len_max, (int)v.size() * 2);
                for (int i = 1; i < v.size() + 1; i++) {
                    if (i == 51) break;
                    arr[y][i * 2 - 1] = v[i - 1].first;
                    arr[y][i * 2] = v[i - 1].second;
                }
            }
            x_len = x_len_max;
        }
        else {
            int y_len_max = 0;
            for (int x = 1; x <= x_len; x++) {
                fill(num, num + 101, 0);
                fill(check, check + 101, false);
                vector<pair<int, int>> v;
                for (int y = 1; y <= y_len; y++) {
                    if (!arr[y][x]) continue;
                    num[arr[y][x]]++;
                }
                for (int y = 1; y <= y_len; y++) {
                    if (!arr[y][x] || check[arr[y][x]]) continue;
                    v.push_back({ arr[y][x], num[arr[y][x]] });
                    check[arr[y][x]] = true;
                }
                sort(v.begin(), v.end(), comparePairs);
                if (v.size() * 2 < y_len) {
                    for (int i = v.size() * 2 + 1; i <= y_len; i++) {
                        arr[i][x] = 0;
                    }
                }
                y_len_max = max(y_len_max, (int)v.size() * 2);
                for (int i = 1; i < v.size() + 1; i++) {
                    if (i == 51) break;
                    arr[i * 2 - 1][x] = v[i - 1].first;
                    arr[i * 2][x] = v[i - 1].second;
                }
            }
            y_len = y_len_max;
        }
        //debug_print();
    }
    cout << ans;

    return 0;
}
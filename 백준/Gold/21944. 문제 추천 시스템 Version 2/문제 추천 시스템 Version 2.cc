#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

int arr[100001][2];
set<int> s1[101];
set<int> s2[101][101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P, L, G;
    cin >> N;
    while (N--) {
        cin >> P >> L >> G;
        s1[L].insert(P);
        s2[L][G].insert(P);
        arr[P][0] = L; arr[P][1] = G;
    }

    int M;
    cin >> M;
    while (M--) {
        string str;
        cin >> str;
        if (str == "add") {
            cin >> P >> L >> G;
            s1[L].insert(P);
            s2[L][G].insert(P);
            arr[P][0] = L; arr[P][1] = G;
        }
        else if (str == "solved") {
            cin >> P;
            s1[arr[P][0]].erase(P);
            s2[arr[P][0]][arr[P][1]].erase(P);
        }
        else if (str == "recommend") {
            int x; cin >> G >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (!s2[i][G].empty()) {
                        cout << *prev(s2[i][G].end()) << '\n';
                        break;
                    }
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (!s2[i][G].empty()) {
                        cout << *s2[i][G].begin() << '\n';
                        break;
                    }
                }
            }
        }
        else if (str == "recommend2") {
            int x; cin >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (!s1[i].empty()) {
                        cout << *prev(s1[i].end()) << '\n';
                        break;
                    }
                }
            }
            else {
                for (int i = 1; i < 101; i++) {
                    if (!s1[i].empty()) {
                        cout << *s1[i].begin() << '\n';
                        break;
                    }
                }
            }
        }
        else {
            int x; cin >> x >> L;
            bool flag = false;
            if (x == 1) {
                for (int i = L; i <= 100; i++) {
                    if (!s1[i].empty()) {
                        cout << *s1[i].begin() << '\n';
                        if (!flag) flag = true;
                        break;
                    }
                }
            }
            else {
                for (int i = L - 1; i > 0; i--) {
                    if (!s1[i].empty()) {
                        cout << *prev(s1[i].end()) << '\n';
                        if (!flag) flag = true;
                        break;
                    }
                }
            }
            if (!flag) cout << -1 << '\n';
        }
    }

    return 0;
}
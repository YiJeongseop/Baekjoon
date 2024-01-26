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

int arr[100001];
set<int> s[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P, L;
    cin >> N;
    while (N--) {
        cin >> P >> L;
        s[L].insert(P);
        arr[P] = L;
    }

    int M;
    cin >> M;
    while (M--) {
        string str;
        cin >> str;
        if (str == "add") {
            cin >> P >> L;
            s[L].insert(P);
            arr[P] = L;
        }
        else if (str == "solved") {
            cin >> P;
            s[arr[P]].erase(P);
        }
        else {
            int x; cin >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (!s[i].empty()) {
                        cout << *prev(s[i].end()) << '\n';
                        break;
                    }
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (!s[i].empty()) {
                        cout << *s[i].begin() << '\n';
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
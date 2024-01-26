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
using ll = long long;

int arr[250000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> s;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;

        if (s.empty()) {
            arr[p] = 1;
            s.insert(p);
            continue;
        }

        auto it = s.lower_bound(p);

        if (it == s.begin()) {
            arr[p] = arr[*it] + 1;
        }
        else if (it == s.end()) {
            arr[p] = arr[*prev(it)] + 1;
        }
        else {
            arr[p] = max(arr[*prev(it)], arr[*it]) + 1;
        }

        s.insert(p);
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) sum += arr[i];
    cout << sum;

    return 0;
}
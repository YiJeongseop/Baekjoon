#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    bool check[10] = { false, };

    vector<long long> v;
    for (int i = 1; i <= 10; i++) {
        bool check[10] = { false, };
        for (int j = 1; j <= i; j++) {
            check[10 - j] = true;
        }
        do {
            string str = "";
            for (int j = 0; j < 10; j++) {
                if (check[j]) {
                    str += arr[j] + '0';
                }
            }
            reverse(str.begin(), str.end());
            v.push_back(stoll(str));
        } while (next_permutation(check, check + 10));
    }

    sort(v.begin(), v.end());

    if (v.size() - 1 < N) cout << -1;
    else cout << v[N];

    return 0;
}
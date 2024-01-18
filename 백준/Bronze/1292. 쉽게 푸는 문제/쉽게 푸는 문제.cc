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

    int A, B;
    cin >> A >> B;

    int i = 1;
    vector<int> v;
    while (v.size() < 1000) {
        for (int j = 1; j <= i; j++)
            v.push_back(i);
        i++;
    }

    int ans = 0;
    for (int i = A - 1; i < B; i++) {
        ans += v[i];
    }
    cout << ans;

    return 0;
}
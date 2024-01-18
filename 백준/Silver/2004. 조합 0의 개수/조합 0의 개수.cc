#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int func_two(int a) {
    int cnt = 0;
    while (a >= 2) {
        cnt += a / 2;
        a /= 2;
    }
    return cnt;
}

int func_five(int a) {
    int cnt = 0;
    while (a >= 5) {
        cnt += a / 5;
        a /= 5;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int two_cnt = func_two(n) - func_two(n - m) - func_two(m);
    int five_cnt = func_five(n) - func_five(n - m) - func_five(m);

    if (five_cnt < two_cnt) cout << five_cnt;
    else cout << two_cnt;

    return 0;
}
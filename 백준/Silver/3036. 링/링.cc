#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int first;
    cin >> first;
    for (int i = 0; i < N - 1; i++) {
        int nxt, div;
        cin >> nxt;
        div = gcd(first, nxt);
        cout << first / div << "/" << nxt / div << '\n';
    }

    return 0;
}
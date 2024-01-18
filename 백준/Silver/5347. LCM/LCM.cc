#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T, a, b;
    cin >> T;

    while (T--) {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}
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

    int E, S, M;
    cin >> E >> S >> M;

    int i = 1;
    while (true) {
        int tmp = i % 15;
        if (tmp == 0) tmp = 15;
        if (tmp != E) {
            i++;
            continue;
        }
        tmp = i % 28;
        if (tmp == 0) tmp = 28;
        if (tmp != S) {
            i++;
            continue;
        }
        tmp = i % 19;
        if (tmp == 0) tmp = 19;
        if (tmp != M) {
            i++;
            continue;
        }
        cout << i;
        break;
    }

    return 0;
}
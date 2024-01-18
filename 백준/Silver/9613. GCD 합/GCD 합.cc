#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int t;
int arr[100];

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        long long n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
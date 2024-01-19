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

    bool* prime = new bool[1040001];
    fill(prime, prime + 1040001, true);
    prime[1] = false;

    for (int i = 2; i <= (int)sqrt(1040000); i++) {
        if (!prime[i]) continue;
        for (int j = i + i; j <= 1040000; j += i) {
            if (!prime[j]) continue;
            prime[j] = false;
        }
    }

    for (int i = N; i <= 1040000; i++) {
        if (!prime[i]) continue;
        else{
            string str = to_string(i);
            string str2 = str;
            reverse(str2.begin(), str2.end());
            if (str != str2) continue;
            cout << str;
            return 0;
        }
    }

    delete[] prime;

    return 0;
}
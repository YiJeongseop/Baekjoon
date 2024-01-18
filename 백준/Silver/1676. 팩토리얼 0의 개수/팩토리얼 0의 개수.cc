#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int two = 0, five = 0;
    for (int i = N; i > 1; i--) {
        int tmp = i;
        for (int j = 2; j <= tmp; j++) {
            while (tmp % j == 0) {
                tmp /= j;
                if (j == 2) two++;
                else if (j == 5) five++;
            }
        }
    }
    if (two > five) {
        cout << five;
    }
    else {
        cout << two;
    }

    return 0;
}
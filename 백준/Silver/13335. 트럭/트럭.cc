#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int n, w, L, time_ = 0, leave = 0, cur_weight = 0;
int truck[1000];
int bridge[100];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }

    int count = 0;
    while (count != n) {
        time_++;
        for (int i = w - 1; i >= 0; i--) {
            if (bridge[i]) {
                if (i == w - 1) {
                    cur_weight -= bridge[i];
                    count++;
                    bridge[i] = 0;
                }
                else {
                    bridge[i + 1] = bridge[i];
                    bridge[i] = 0;
                }
            }
        }
        if (truck[leave] + cur_weight <= L) {
            bridge[0] = truck[leave];
            cur_weight += truck[leave++];
        }
    }

    cout << time_;

    return 0;
}
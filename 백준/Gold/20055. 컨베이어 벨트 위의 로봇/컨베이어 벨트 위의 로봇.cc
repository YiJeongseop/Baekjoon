#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, K, step = 1;
int conveyor[201];
int robot[201];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int up_pos = 1, down_pos = N;
    for (int i = 1; i <= (2 * N); i++) {
        cin >> conveyor[i];
    }

    while (true) {
        up_pos--;
        if (up_pos == 0) up_pos = 2 * N;

        down_pos--;
        if (down_pos == 0) down_pos = 2 * N;

        if (robot[down_pos] != 0) robot[down_pos] = 0;

        for (int i = down_pos - 1; i > down_pos - N + 1; i--) {
            int temp = i;
            if (temp <= 0) temp += 2 * N;
            int temp2 = temp + 1;
            if (temp == 2 * N) temp2 = 1;
            if (robot[temp] == 1 && conveyor[temp2] > 0 && robot[temp2] == 0) {
                if (temp2 != down_pos) {
                    robot[temp2] = 1;
                }
                robot[temp] = 0;
                conveyor[temp2]--; 
            }
        }

        if (conveyor[up_pos] > 0) {
            robot[up_pos] = 1;
            conveyor[up_pos]--;
        }

        int cnt = 0;
        for (int i = 1; i <= 2 * N; i++) {
            if (conveyor[i] <= 0) cnt++;
        }

        if (cnt >= K) {
            cout << step;
            break;
        }
        step++;
    }

    return 0;
}
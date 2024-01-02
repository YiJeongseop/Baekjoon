#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int number[5][9];
int state[5][9];
int check_arr[4];
int K;


void rotate(int num, int dir) {
    if (dir == 1) {
        int temp = state[num][8];
        for (int i = 8; i > 0; i--) {
            state[num][i] = state[num][i - 1];
        }
        state[num][1] = temp;
    }
    else if (dir == -1) {
        int temp = state[num][1];
        for (int i = 1; i < 8; i++) {
            state[num][i] = state[num][i + 1];
        }
        state[num][8] = temp;
    }
}

void check() {
    if (number[1][state[1][3]] != number[2][state[2][7]]) {
        check_arr[1] = 1;
    }
    else {
        check_arr[1] = 0;
    }

    if (number[2][state[2][3]] != number[3][state[3][7]]) {
        check_arr[2] = 1;
    }
    else {
        check_arr[2] = 0;
    }

    if (number[3][state[3][3]] != number[4][state[4][7]]) {
        check_arr[3] = 1;
    }
    else {
        check_arr[3] = 0;
    }
}

void debug_print() {
    cout << '\n';
    cout << "1번 톱니바퀴 상태 " << '\n';
    for (int i = 1; i < 9; i++) {
        cout << state[1][i] << " ";
    }
    cout << '\n';
    cout << "2번 톱니바퀴 상태 " << '\n';
    for (int i = 1; i < 9; i++) {
        cout << state[2][i] << " ";
    }
    cout << '\n';
    cout << "3번 톱니바퀴 상태 " << '\n';
    for (int i = 1; i < 9; i++) {
        cout << state[3][i] << " ";
    }
    cout << '\n';
    cout << "4번 톱니바퀴 상태 " << '\n';
    for (int i = 1; i < 9; i++) {
        cout << state[4][i] << " ";
    }
    cout << '\n';
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string temp;
    for (int i = 1; i < 5; i++) {
        cin >> temp;
        for (int j = 0; j < 8; j++) {
            number[i][j + 1] = temp[j] - '0';
        }
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j <= 8; j++) {
            state[i][j] = j;
        }
    }

    cin >> K;
    while (K--) {
        int num, dir;
        cin >> num >> dir;

        // debug_print();

        check();
        rotate(num, dir);
        int temp = dir;
        if (num != 4) {
            for (int i = num; i <= 3; i++) {
                if (check_arr[i]) {
                    rotate(i + 1, dir * -1);
                    dir *= -1;
                }
                else {
                    break;
                }
            }
            dir = temp;
            for (int i = num - 1; i > 0; i--) {
                if (check_arr[i]) {
                    rotate(i, dir * -1);
                    dir *= -1;
                }
                else {
                    break;
                }
            }
        }
        else {
            for (int i = 3; i > 0; i--) {
                if (check_arr[i]) {
                    rotate(i, dir * -1);
                    dir *= -1;
                }
                else {
                    break;
                }
            }
        }

        // debug_print();
    }

    int ans = 0;
    for (int i = 1; i < 5; i++) {
        // cout << number[i][state[i][1]] << '\n';
        if (number[i][state[i][1]]) {
            ans += pow(2, i - 1);
        }
    }
    cout << ans;

    return 0;
}
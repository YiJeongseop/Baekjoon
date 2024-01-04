#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N;
int arr[50][9];
int real_order[9];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    int order[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    real_order[3] = 0;
    do {
        copy(order, order + 3, real_order);
        copy(order + 3, order + 8, real_order + 4);
        int score = 0;
        int next_player = 0;
        for (int i = 0; i < N; i++) {
            int stage[3] = { 0, 0, 0 };
            int out_count = 0;
            while (out_count < 3) {
                if (arr[i][real_order[next_player]] == 0) {
                    out_count++;
                }
                else if (arr[i][real_order[next_player]] == 1) {
                    if (stage[2]) {
                        score++;
                        stage[2] = 0;
                    }
                    if (stage[1]) {
                        stage[2] = 1;
                        stage[1] = 0;
                    }
                    if (stage[0]) {
                        stage[1] = 1;
                        stage[0] = 0;
                    }
                    stage[0] = 1;
                }
                else if (arr[i][real_order[next_player]] == 2) {
                    if (stage[2]) {
                        score++;
                        stage[2] = 0;
                    }
                    if (stage[1]) {
                        score++;
                        stage[1] = 0;
                    }
                    if (stage[0]) {
                        stage[2] = 1;
                        stage[0] = 0;
                    }
                    stage[1] = 1;
                }
                else if (arr[i][real_order[next_player]] == 3) {
                    if (stage[2]) {
                        score++;
                        stage[2] = 0;
                    }
                    if (stage[1]) {
                        score++;
                        stage[1] = 0;
                    }
                    if (stage[0]) {
                        score++;
                        stage[0] = 0;
                    }
                    stage[2] = 1;
                }
                else if (arr[i][real_order[next_player]] == 4) {
                    score += (stage[0] + stage[1] + stage[2] + 1);
                    stage[0] = 0; stage[1] = 0; stage[2] = 0;
                }
                next_player++;
                if (next_player == 9) next_player = 0;
            }
        }
        ans = max(ans, score);
    } while (next_permutation(order, order + 8));

    cout << ans;

    return 0;
}
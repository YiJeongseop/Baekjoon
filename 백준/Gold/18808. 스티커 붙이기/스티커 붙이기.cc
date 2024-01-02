#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, K, R, C;
int board[41][41];
int sticker[5][101][11][11];
vector<pair<int, int>> sticker_size;

bool check(int y, int x, int sticker_num, int sticker_x, int sticker_y, int rotation) {
    for (int y_ = 1; y_ <= sticker_y; y_++) {
        for (int x_ = 1; x_ <= sticker_x; x_++) {
            if (y + y_ - 1 > N || x + x_ - 1 > M) return false;
            if (sticker[rotation][sticker_num][y_][x_] && board[y + y_ - 1][x + x_ - 1]) {
                return false;
            }
        }
    }

    for (int y_ = 1; y_ <= sticker_y; y_++) {
        for (int x_ = 1; x_ <= sticker_x; x_++) {
            if (sticker[rotation][sticker_num][y_][x_]) {
                board[y + y_ - 1][x + x_ - 1] = 1;
                // cout << "board[" << y + y_ - 1 << "][" << x + x_ - 1 << "]에 1이 들어갔습니다! " << '\n';
            }
            else {
                continue;
            }
        }
    }

    //cout << "현재 board의 상태입니다! " << '\n';
    //for (int y_ = 1; y_ <= N; y_++) {
    //    for (int x_ = 1; x_ <= M; x_++) {
    //        cout << board[y_][x_] << " ";
    //    }
    //    cout << '\n';
    //}

    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= K; i++) {
        cin >> R >> C;
        sticker_size.push_back({ R, C });
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                cin >> sticker[1][i][y][x];
                sticker[2][i][x][R - y + 1] = sticker[1][i][y][x];
            }
        }

        for (int y = 1; y <= C; y++) {
            for (int x = 1; x <= R; x++) {
                sticker[3][i][x][C - y + 1] = sticker[2][i][y][x];
            }
        }

        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                sticker[4][i][x][R - y + 1] = sticker[3][i][y][x];
            }
        }

        //cout << "=====스티커 회전 1=====" << '\n';
        //for (int y = 1; y <= R; y++) {
        //    for (int x = 1; x <= C; x++) {
        //        cout << sticker[1][i][y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << "============================" << '\n';
        //cout << "=====스티커 회전 2=====" << '\n';
        //for (int y = 1; y <= C; y++) {
        //    for (int x = 1; x <= R; x++) {
        //        cout << sticker[2][i][y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << "============================" << '\n';
        //cout << "=====스티커 회전 3=====" << '\n';
        //for (int y = 1; y <= R; y++) {
        //    for (int x = 1; x <= C; x++) {
        //        cout << sticker[3][i][y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << "============================" << '\n';
        //cout << "=====스티커 회전 4=====" << '\n';
        //for (int y = 1; y <= C; y++) {
        //    for (int x = 1; x <= R; x++) {
        //        cout << sticker[4][i][y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << "============================" << '\n';
    }

    for (int i = 1; i <= K; i++) {
        bool flag = false;
        int y, x;
        tie(y, x) = sticker_size[i - 1];
        //cout << "현재 스티커의 높이는 " << y << "이며, 넓이는 " << x << "입니다! " << '\n';
        //if (y == 2 && x == 5) {
        //    cout << " 잠시 디버그 " << '\n';
        //}
        for (int rotation = 1; rotation < 5; rotation++) {
            if (rotation == 1 && y <= N && x <= M) {
                for (int y_ = 1; y_ <= N; y_++) {
                    for (int x_ = 1; x_ <= M; x_++) {
                        if (check(y_, x_, i, x, y, 1)) {
                            flag = true;
                            break;
                       }
                    }
                    if (flag) break;
                }
            }
            else if (rotation == 2 && x <= N && y <= M) {
                for (int y_ = 1; y_ <= N; y_++) {
                    for (int x_ = 1; x_ <= M; x_++) {
                        if (check(y_, x_, i, y, x, 2)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
            else if (rotation == 3 && y <= N && x <= M) {
                for (int y_ = 1; y_ <= N; y_++) {
                    for (int x_ = 1; x_ <= M; x_++) {
                        if (check(y_, x_, i, x, y, 3)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
            else if (rotation == 4 && x <= N && y <= M) {
                for (int y_ = 1; y_ <= N; y_++) {
                    for (int x_ = 1; x_ <= M; x_++) {
                        if (check(y_, x_, i, y, x, 4)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
            if (flag) break;
        }
    }

    int ans = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            if (board[y][x] != 0) ans++;
        }
    }

    cout << ans;

    return 0;
}
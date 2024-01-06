#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, ans = INT_MAX;
int city[21][21];
int board[21][21];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[5];

bool check(int x, int y, int d1, int d2) {
    if (x >= x + d1 + d2 || x + d1 + d2 > N) return false;
    if (y - d1 < 1 || y <= y - d1 || y >= y + d2 || y + d2 > N) return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> city[y][x];
        }
    }

    for (int x = 1; x <= N - 2; x++) {
        for (int y = 2; y <= N - 1; y++) {
            for (int d1 = 1; d1 <= N - 2; d1++) {
                for (int d2 = 1; d2 <= N - 2; d2++) {
                    if (check(x, y, d1, d2)) {
                        //cout << "x : " << x << ", y : " << y << ", d1 : " << d1 << ", d2 : " << d2 << "\n";
                        for (int i = 1; i <= N; i++)
                            fill(board[i], board[i] + N + 1, 0);
                        fill(arr, arr + 5, 0);
                        board[x][y] = 5;
                        for (int i = 1; i <= d1; i++) {
                            board[x + i][y - i] = 5;
                            board[x + d2 + i][y + d2 - i] = 5;
                        }
                        for (int i = 1; i <= d2; i++) {
                            board[x + i][y + i] = 5;
                            board[x + d1 + i][y - d1 + i] = 5;
                        }
                        //cout << "1. board" << '\n';
                        //for (int i = 1; i <= N; i++) {
                        //    for (int j = 1; j <= N; j++) {
                        //        cout << board[i][j] << " ";
                        //    }
                        //    cout << '\n';
                        //}

                        for (int i = y - d1 + 1; i < y + d2; i++) {
                            bool flag1 = false;
                            for (int j = 1; j <= N; j++) {
                                if (board[j][i] == 5) {
                                    if (flag1) flag1 = false;
                                    else flag1 = true;
                                }
                                else if (flag1) {
                                    board[j][i] = 5;
                                    // cout << "board[" << i << "][" << j << "]에 5를 대입합니다. " << '\n';
                                }
                            }
                        }

                        //queue<pair<int, int>> q;
                        //q.push({ x + 1, y });
                        //board[x + 1][y] = 5;
                        //while (!q.empty()) {
                        //    auto cur = q.front();
                        //    q.pop();
                        //    for (int dir = 0; dir < 4; dir++) {
                        //        int nx = cur.first + dx[dir];
                        //        int ny = cur.second + dy[dir];
                        //        if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
                        //        if (board[nx][ny] == 5) continue;
                        //        board[nx][ny] = 5;
                        //        q.push({ nx, ny });
                        //    }
                        //}
                        //cout << "2. board" << '\n';
                        //for (int i = 1; i <= N; i++) {
                        //    for (int j = 1; j <= N; j++) {
                        //        cout << board[i][j] << " ";
                        //    }
                        //    cout << '\n';
                        //}

                        for (int i = 1; i <= N; i++) {
                            for (int j = 1; j <= N; j++) {
                                if (board[i][j] == 0) {
                                    if (j <= y && i < x + d1) board[i][j] = 1;
                                    else if (j > y && i <= x + d2) board[i][j] = 2;
                                    else if (j < y + d2 - d1 && i >= x + d1) board[i][j] = 3;
                                    else if (j >= y + d2 - d1 && i > x + d2) board[i][j] = 4;
                                }
                            }
                        }

                        //cout << "3. board" << '\n';
                        //for (int i = 1; i <= N; i++) {
                        //    for (int j = 1; j <= N; j++) {
                        //        cout << board[i][j] << " ";
                        //    }
                        //    cout << '\n';
                        //}

                        for (int i = 1; i <= N; i++) {
                            for (int j = 1; j <= N; j++) {
                                arr[board[i][j] - 1] += city[i][j];
                            }
                        }

                        sort(arr, arr + 5);

                        ans = min(ans, arr[4] - arr[0]);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
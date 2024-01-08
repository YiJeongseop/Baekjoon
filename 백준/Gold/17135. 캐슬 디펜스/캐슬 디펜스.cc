#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, D, ans = 0;
int board[16][16];
int board2[16][16];
int dis[16][16];
int archer[16];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

//void debug_print() {
//    debug_num++;
//    cout << '\n';
//    cout << "현재 board2" << '\n';
//    for (int y = 1; y <= 5; y++) {
//        for (int x = 1; x <= 5; x++) {
//            cout << board2[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> board[y][x];
        }
    }

    for (int i = M; i > M - 3; i--)
        archer[i] = 1;

    do {
        int cnt = 0;
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                board2[y][x] = board[y][x];
            }
        }

        while (true) {
            //cout << '\n';
            //cout << " 공격 전 " << '\n';
            //debug_print();
            // 공격
            vector<pair<int, int>> v;
            for (int i = 1; i <= M; i++) {
                if (archer[i]) {
                    for (int y = 1; y <= N; y++) {
                        for (int x = 1; x <= M; x++) {
                            dis[y][x] = 0;
                        }
                    }

                    dis[N][i] = 1;
                    queue<pair<int, int>> q;
                    q.push({ N, i });
                    pair<int, int> temp = { 0, 0 };
                    int temp_dis = INT_MAX;
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        if (dis[cur.first][cur.second] > temp_dis) {
                            v.push_back({ temp.first, temp.second });
                            break;
                        }
                        if (dis[cur.first][cur.second] > D) break;
                        if (board2[cur.first][cur.second] && dis[cur.first][cur.second] <= D) {
                            if (temp.first == 0 && temp.second == 0) {
                                temp.first = cur.first;
                                temp.second = cur.second;
                                temp_dis = dis[temp.first][temp.second];
                            }
                            else {
                                if (cur.second < temp.second) {
                                    temp.first = cur.first;
                                    temp.second = cur.second;
                                }
                            }
                        }
                        for (int dir = 0; dir < 4; dir++) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (ny <= 0 || nx <= 0 || ny > N || nx > M || dis[ny][nx] != 0) continue;
                            dis[ny][nx] = dis[cur.first][cur.second] + 1;
                            q.push({ ny, nx });
                        }
                    }
                }
            }
            for (int i = 0; i < v.size(); i++) {
                if (board2[v[i].first][v[i].second] == 0) continue;
                board2[v[i].first][v[i].second] = 0;
                cnt++;
            }

            bool flag2 = true;
            for (int y = 1; y <= N; y++) {
                for (int x = 1; x <= M; x++) {
                    if (board2[y][x] == 1) {
                        flag2 = false;
                    }
                }
            }

            //cout << '\n';
            //cout << " 공격 후 " << '\n';
            //debug_print();

            if (flag2) {
                ans = max(ans, cnt);
                //cout << " 게임 종료, ans가 " << ans << "로 갱신되었습니다." << '\n';
                break;
            }

            // 이동
            for (int y = N; y > 0; y--) {
                for (int x = 1; x <= M; x++) {
                    if (y == N && board2[y][x] == 1) {
                        board2[y][x] = 0;
                    }
                    else if (y != N && board2[y][x] == 1) {
                        board2[y][x] = 0;
                        board2[y + 1][x] = 1;
                    }
                }
            }

            //cout << '\n';
            //cout << " 이동 후 " << '\n';
            //debug_print();
        }
    } while (next_permutation(archer + 1, archer + M + 1));

    cout << ans;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, K;
vector<tuple<int, int, int>> board[51][51];
vector<tuple<int, int, int>> temp_board[51][51];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({ m, s, d }); //r행 c열 질량 방향 속력
    }

    while (K--) {
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (board[y][x].size() == 1) {
                    int m = get<0>(board[y][x][0]);
                    int s = get<1>(board[y][x][0]);
                    int d = get<2>(board[y][x][0]);
                    board[y][x].clear();
                    int ny = y + dy[d] * s;
                    int nx = x + dx[d] * s;
                    if (ny <= 0) {
                        ny = N - (abs(ny) % N);
                    }
                    else if (ny > N) {
                        ny = ny % N;
                        if (ny == 0) ny = N;
                    }
                    if (nx <= 0) {
                        nx = N - (abs(nx) % N);
                    }
                    else if (nx > N) {
                        nx = nx % N;
                        if (nx == 0) nx = N;
                    }
                    temp_board[ny][nx].push_back({ m, s, d });
                }
                else if (board[y][x].size() > 1) {
                    for (int i = 0; i < board[y][x].size(); i++) {
                        int m = get<0>(board[y][x][i]);
                        int s = get<1>(board[y][x][i]);
                        int d = get<2>(board[y][x][i]);
                        int ny = y + dy[d] * s;
                        int nx = x + dx[d] * s;
                        if (ny <= 0) {
                            ny = N - (abs(ny) % N);
                        }
                        else if (ny > N) {
                            ny = ny % N;
                            if (ny == 0) ny = N;
                        }
                        if (nx <= 0) {
                            nx = N - (abs(nx) % N);
                        }
                        else if (nx > N) {
                            nx = nx % N;
                            if (nx == 0) nx = N;
                        }
                        temp_board[ny][nx].push_back({ m, s, d });
                    }
                    board[y][x].clear();
                }
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (temp_board[y][x].size() > 0) {
                    board[y][x] = temp_board[y][x];
                    temp_board[y][x].clear();
                }
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (board[y][x].size() > 1) {
                    int m_sum = 0, s_sum = 0;
                    int temp1 = 0, temp2 = 0;
                    for (int i = 0; i < board[y][x].size(); i++) {
                        int m = get<0>(board[y][x][i]);
                        int s = get<1>(board[y][x][i]);
                        int d = get<2>(board[y][x][i]);
                        if (d % 2 == 0) temp1++;
                        else temp2++;
                        m_sum += m;
                        s_sum += s;
                    }
                    int m = m_sum / 5;
                    if (m == 0) {
                        board[y][x].clear();
                        continue;
                    }
                    int s = s_sum / board[y][x].size();
                    board[y][x].clear();
                    if (temp1 == 0 || temp2 == 0) {
                        board[y][x].push_back({ m, s, 0 });
                        board[y][x].push_back({ m, s, 2 });
                        board[y][x].push_back({ m, s, 4 });
                        board[y][x].push_back({ m, s, 6 });
                    }
                    else {
                        board[y][x].push_back({ m, s, 1 });
                        board[y][x].push_back({ m, s, 3 });
                        board[y][x].push_back({ m, s, 5 });
                        board[y][x].push_back({ m, s, 7 });
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (board[y][x].size() > 0) {
                for (int i = 0; i < board[y][x].size(); i++) {
                    ans += get<0>(board[y][x][i]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
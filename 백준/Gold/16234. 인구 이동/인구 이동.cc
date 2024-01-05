#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, L, R, r, c;
int land[50][50];
int visited[50][50];
bool border[50][50][50][50];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void reset_border() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                fill(border[i][j][k], border[i][j][k] + N, false);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + N, 0);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> land[y][x];
        }
    }

    int ans = 0;
    while (true) {
        reset_border();
        bool flag = false;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (x != N - 1 && abs(land[y][x] - land[y][x + 1]) >= L && abs(land[y][x] - land[y][x + 1]) <= R) {
                    border[y][x][y][x + 1] = true;
                    border[y][x + 1][y][x] = true;
                    flag = true;
                }
                if (y != N - 1 && abs(land[y][x] - land[y + 1][x]) >= L && abs(land[y][x] - land[y + 1][x]) <= R) {
                    border[y][x][y + 1][x] = true;
                    border[y + 1][x][y][x] = true;
                    flag = true;
                }
            }
        }
        if (!flag) break;
        ans++;

        queue<pair<int, int>> q;
        queue<pair<int, int>> q2;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x]) {
                    q.push({ y, x });
                    q2.push({ y, x });
                    visited[y][x] = true;
                    int sum = land[y][x];
                    int cnt = 1;
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.second + dx[dir];
                            int ny = cur.first + dy[dir];
                            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if (visited[ny][nx] || !border[cur.first][cur.second][ny][nx]) continue;
                            cnt++;
                            sum += land[ny][nx];
                            visited[ny][nx] = true;
                            q.push({ ny, nx });
                            q2.push({ ny, nx });
                        }
                    }
                    while (!q2.empty()) {
                        auto cur = q2.front();
                        q2.pop();
                        land[cur.first][cur.second] = sum / cnt;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
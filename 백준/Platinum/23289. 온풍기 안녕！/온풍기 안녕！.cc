#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int R, C, K, W, chocolate = 0;
int room[21][21];
int room2[21][21];
int visited[21][21];
int wall[21][21][2];
vector<pair<int, int>> target;
vector<tuple<int, int, int>> fan_heater; // y x 방향(1-오 2-왼 3-위 4-아래)
int dx_r[3] = { 1, 1, 1 };
int dy_r[3] = { -1, 0, 1 };
int dx_l[3] = { -1, -1, -1 };
int dy_l[3] = { -1, 0, 1 };
int dx_u[3] = { -1, 0, 1 };
int dy_u[3] = { -1, -1, -1 };
int dx_d[3] = { -1, 0, 1 };
int dy_d[3] = { 1, 1, 1 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//void debug_print() {
//    cout << "방 상태입니다." << '\n';
//    for (int y = 1; y <= R; y++) {
//        for (int x = 1; x <= C; x++) {
//            cout << room[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}
//
//void debug_print2() {
//    cout << "방2 상태입니다." << '\n';
//    for (int y = 1; y <= R; y++) {
//        for (int x = 1; x <= C; x++) {
//            cout << room2[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> K;

    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cin >> room[y][x];
            if (room[y][x] == 5) {
                target.push_back({ y, x });
                room[y][x] = 0;
            }
            else if (room[y][x] < 5 && room[y][x] > 0) {
                fan_heater.push_back({ y, x, room[y][x] });
                room[y][x] = 0;
            }
        }
    }

    cin >> W;
    for (int i = 0; i < W; i++) {
        int a, b, c;
        cin >> a >> b >> c; // 행 열 0-위1-오른쪽
        wall[a][b][c] = 1;
    }

    while (chocolate <= 100) {
        // 1단계
        for (int i = 0; i < fan_heater.size(); i++) {
            int y, x, di;
            tie(y, x, di) = fan_heater[i];
            if (di == 1) {
                if (x + 1 > C || wall[y][x][1]) continue;
                queue<tuple<int, int, int>> q;
                for (int j = 1; j <= R; j++)
                    fill(visited[j] + 1, visited[j] + C + 1, false);
                q.push({ y, x + 1, 5 });
                room[y][x + 1] += 5;
                visited[y][x + 1] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (get<2>(cur) == 0) break;
                    for (int dir = 0; dir < 3; dir++) {
                        int ny = get<0>(cur) + dy_r[dir];
                        int nx = get<1>(cur) + dx_r[dir];
                        if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                        if (dir == 1 && wall[get<0>(cur)][get<1>(cur)][1]) continue;
                        if (dir == 0 && (wall[get<0>(cur) - 1][get<1>(cur)][1] || wall[get<0>(cur)][get<1>(cur)][0])) continue;
                        if (dir == 2 && (wall[get<0>(cur) + 1][get<1>(cur)][1] || wall[get<0>(cur) + 1][get<1>(cur)][0])) continue;
                        if (visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        room[ny][nx] += get<2>(cur) - 1;
                        q.push({ ny, nx, get<2>(cur) - 1 });
                    }
                }
            }
            else if (di == 2) {
                if (x - 1 <= 0 || wall[y][x - 1][1]) continue;
                queue<tuple<int, int, int>> q;
                for (int j = 1; j <= R; j++)
                    fill(visited[j] + 1, visited[j] + C + 1, false);
                q.push({ y, x - 1, 5 });
                room[y][x - 1] += 5;
                visited[y][x - 1] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (get<2>(cur) == 0) break;
                    for (int dir = 0; dir < 3; dir++) {
                        int ny = get<0>(cur) + dy_l[dir];
                        int nx = get<1>(cur) + dx_l[dir];
                        if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                        if (dir == 1 && wall[get<0>(cur)][get<1>(cur) - 1][1]) continue;
                        if (dir == 0 && (wall[get<0>(cur) - 1][get<1>(cur) - 1][1] || wall[get<0>(cur)][get<1>(cur)][0])) continue;
                        if (dir == 2 && (wall[get<0>(cur) + 1][get<1>(cur) - 1][1] || wall[get<0>(cur) + 1][get<1>(cur)][0])) continue;
                        if (visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        room[ny][nx] += get<2>(cur) - 1;
                        q.push({ ny, nx, get<2>(cur) - 1 });
                    }
                }
            }
            else if (di == 3) {
                if (y - 1 <= 0 || wall[y][x][0]) continue;
                queue<tuple<int, int, int>> q;
                for (int j = 1; j <= R; j++)
                    fill(visited[j] + 1, visited[j] + C + 1, false);
                q.push({ y - 1, x, 5 });
                room[y - 1][x] += 5;
                visited[y - 1][x] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (get<2>(cur) == 0) break;
                    for (int dir = 0; dir < 3; dir++) {
                        int ny = get<0>(cur) + dy_u[dir];
                        int nx = get<1>(cur) + dx_u[dir];
                        if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                        if (dir == 1 && wall[get<0>(cur)][get<1>(cur)][0]) continue;
                        if (dir == 0 && (wall[get<0>(cur)][get<1>(cur) - 1][1] || wall[get<0>(cur)][get<1>(cur) - 1][0])) continue;
                        if (dir == 2 && (wall[get<0>(cur)][get<1>(cur)][1] || wall[get<0>(cur)][get<1>(cur) + 1][0])) continue;
                        if (visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        room[ny][nx] += get<2>(cur) - 1;
                        q.push({ ny, nx, get<2>(cur) - 1 });
                    }
                }
            }
            else {
                if (y + 1 > R || wall[y + 1][x][0]) continue;
                queue<tuple<int, int, int>> q;
                for (int j = 1; j <= R; j++)
                    fill(visited[j] + 1, visited[j] + C + 1, false);
                q.push({ y + 1, x, 5 });
                room[y + 1][x] += 5;
                visited[y + 1][x] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (get<2>(cur) == 0) break;
                    for (int dir = 0; dir < 3; dir++) {
                        int ny = get<0>(cur) + dy_d[dir];
                        int nx = get<1>(cur) + dx_d[dir];
                        if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                        if (dir == 1 && wall[get<0>(cur) + 1][get<1>(cur)][0]) continue;
                        if (dir == 0 && (wall[get<0>(cur)][get<1>(cur) - 1][1] || wall[get<0>(cur) + 1][get<1>(cur) - 1][0])) continue;
                        if (dir == 2 && (wall[get<0>(cur)][get<1>(cur)][1] || wall[get<0>(cur) + 1][get<1>(cur) + 1][0])) continue;
                        if (visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        room[ny][nx] += get<2>(cur) - 1;
                        q.push({ ny, nx, get<2>(cur) - 1 });
                    }
                }
            }
            //debug_print();
        }
    
        // 2단계
        for (int y = 1; y <= R; y++)
            fill(room2[y] + 1, room2[y] + 1 + C, 0);

        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                    if (dir == 0 && wall[y][x][1]) continue;
                    if (dir == 1 && wall[y + 1][x][0]) continue;
                    if (dir == 2 && wall[y][x - 1][1]) continue;
                    if (dir == 3 && wall[y][x][0]) continue;
                    if (room[ny][nx] >= room[y][x]) continue;
                    int val = (room[y][x] - room[ny][nx]) / 4;
                    room2[y][x] -= val;
                    room2[ny][nx] += val;
                }
            }
        }
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                room[y][x] += room2[y][x];
            }
        }
        //debug_print2();

        // 3단계
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                if (y == 1 || x == 1 || y == R || x == C) {
                    if (room[y][x] > 0) room[y][x]--;
                }
            }
        }

        //debug_print();

        // 4단계
        chocolate++;

        // 5단계
        bool flag = false;
        for (int i = 0; i < target.size(); i++) {
            if (room[target[i].first][target[i].second] < K) {
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }

    if (chocolate > 100) cout << 101;
    else cout << chocolate;

    return 0;
}
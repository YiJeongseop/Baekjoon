#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };
int board[21][21];
int target[403][21][21];
int dis[21][21];
int N, M, fuel, start_y, start_x, guest;
queue<pair<int, int>> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> fuel;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> board[y][x];
        }
    }

    cin >> start_y >> start_x;

    int gs_y, gs_x, ge_y, ge_x;
    for (int i = 2; i <= M + 1; i++) {
        cin >> gs_y >> gs_x >> ge_y >> ge_x;
        board[gs_y][gs_x] = i;
        target[i][ge_y][ge_x] = -i;
    }

    //cout << "board" << '\n';
    //for (int i = 1; i <= 6; i++) {
    //    for (int j = 1; j <= 6; j++) {
    //        cout << board[i][j] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    int cnt = 0;
    while (cnt != M) {
        q.push({ start_y, start_x });
        dis[start_y][start_x] = 1;
        int temp = INT_MAX;
        int guest_y = INT_MAX, guest_x = INT_MAX;

        //if (cnt == 3) {
        //    cout << "디버그 시작" << '\n';
        //}

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (board[cur.first][cur.second] > 1) {
                guest = board[cur.first][cur.second];
                guest_y = cur.first;
                guest_x = cur.second;
                temp = dis[cur.first][cur.second] - 1;
            }
            if (dis[cur.first][cur.second] > temp) break;
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if (dis[ny][nx] != 0 || board[ny][nx] == 1) continue;
                dis[ny][nx] = dis[cur.first][cur.second] + 1;
                if (board[ny][nx] > 1) {
                    if (guest_y < ny) continue;
                    if (guest_y == ny && guest_x < nx) continue;
                    guest = board[ny][nx];
                    guest_y = ny;
                    guest_x = nx;
                    temp = dis[cur.first][cur.second];
                    continue;
                }
                q.push({ ny, nx });
            }
        }
        if (guest_y == INT_MAX) {
            cout << -1;
            return 0;
        }

        fuel -= temp;
        //cout << "현재 연료는 " << fuel << "입니다. " << '\n';
        start_x = guest_x;
        start_y = guest_y;
        board[guest_y][guest_x] = 0;
        //cout << guest << "번 승객을 태웠습니다. " << '\n';

        if (fuel < 0) {
            cout << -1;
            return 0;
        }

        while (!q.empty()) q.pop();

        //cout << "dis" << '\n';
        //for (int i = 1; i <= 6; i++) {
        //    for (int j = 1; j <= 6; j++) {
        //        cout << dis[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int y = 1; y <= N; y++)
            fill(dis[y], dis[y] + N + 1, 0);

        q.push({ start_y, start_x });
        dis[start_y][start_x] = 1;
        bool flag2 = false;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if (dis[ny][nx] != 0 || board[ny][nx] == 1) continue;
                dis[ny][nx] = dis[cur.first][cur.second] + 1;
                if (target[guest][ny][nx] == (guest * -1)) {
                    fuel -= dis[cur.first][cur.second];
                    //cout << "현재 연료는 " << fuel << "입니다. " << '\n';
                    if (fuel < 0) {
                        cout << -1;
                        return 0;
                    }
                    fuel += (dis[cur.first][cur.second] * 2);
                    //cout << "현재 연료는 " << fuel << "입니다. " << '\n';
                    start_x = nx;
                    start_y = ny;
                    //cout << guest << "번 승객을 내렸습니다. " << '\n';
                    flag2 = true;
                    cnt++;
                    break;
                }
                q.push({ ny, nx });
            }
            if (flag2) break;
        }

        while (!q.empty()) q.pop();

        if (!flag2) {
            cout << -1;
            return 0;
        }

        //cout << "dis" << '\n';
        //for (int i = 1; i <= 6; i++) {
        //    for (int j = 1; j <= 6; j++) {
        //        cout << dis[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int y = 1; y <= N; y++)
            fill(dis[y], dis[y] + N + 1, 0);

        //cout << "현재 cnt는 " << cnt << "입니다." << '\n';
    }

    cout << fuel;

    return 0;
}
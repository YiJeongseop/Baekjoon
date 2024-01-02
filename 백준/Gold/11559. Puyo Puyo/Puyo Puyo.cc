#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char field[12][6];
bool visited[12][6];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int, int, char>> q;

    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 6; x++) {
            cin >> field[y][x];
        }
    }

    int ans = 0;

    int ans_temp = -1;
    while (ans != ans_temp) {
        for (int y = 0; y < 12; y++) {
            fill(visited[y], visited[y] + 6, false);
        }
        ans_temp = ans;
        bool plus_flag = false;
        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {
                if (field[y][x] != '.' && !visited[y][x]) {
                    // cout << y << ", " << x << "를 돌립니다!" << '\n';
                    vector<pair<int, int>> bomb;
                    bomb.push_back({ y, x });
                    q.push({ y, x, field[y][x] });
                    visited[y][x] = true;
                    int cnt = 1;
                    while (!q.empty()) {
                        int y, x;
                        char color;
                        tie(y, x, color) = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int ny = y + dy[dir];
                            int nx = x + dx[dir];
                            if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
                            if (visited[ny][nx] || field[ny][nx] != color) continue;
                            cnt++;
                            bomb.push_back({ ny, nx });
                            visited[ny][nx] = true;
                            q.push({ ny, nx, color });
                        }
                    }
                    if (cnt >= 4) {
                        if (!plus_flag) {
                            ans++;
                            plus_flag = true;
                        }
                        for (auto& pos : bomb) {
                            field[pos.first][pos.second] = '.';
                        }
                    }
                }
            }
        }

        //cout << "\n";
        //for (int y = 0; y < 12; y++) {
        //    for (int x = 0; x < 6; x++) {
        //        cout << field[y][x];
        //    }
        //    cout << "\n";
        //}
        //cout << "\n";

        if (ans_temp != ans) {
            for (int x = 0; x < 6; x++) {
                for (int y = 11; y >= 0; y--) {
                    if (field[y][x] != '.') {
                        int temp = y;
                        if (temp == 11) continue;
                        while (field[temp + 1][x] == '.') {
                            swap(field[temp][x], field[temp + 1][x]);
                            temp++;
                            if (temp == 12) break;
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
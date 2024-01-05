#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int R, C, T;
int room[51][51];
int room2[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
pair<int, int> air_cleaner = { 0, 0 };
queue<pair<int, int>> q;

void debug_print() {
    cout << '\n';
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cout << room[y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cin >> room[y][x];
            if (room[y][x] == -1) {
                if (air_cleaner.first) air_cleaner.second = y;
                else air_cleaner.first = y;
            }
            else if (room[y][x] != 0) {
                room2[y][x] = room[y][x];
                q.push({ y, x });
            }
        }
    }

    while (T--) {
        while (!q.empty()) {
            int y, x;
            tie(y, x) = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx <= 0 || ny <= 0 || nx > C || ny > R) continue;
                if (room[ny][nx] == -1) continue;
                room[ny][nx] += room2[y][x] / 5;
                room[y][x] -= room2[y][x] / 5;
            }
        }

        //cout << "미세먼지가 퍼집니다. " << '\n';
        //debug_print();

        for (int y = air_cleaner.first - 2; y >= 1; y--) {
            room[y + 1][1] = room[y][1];
        }
        for (int x = 2; x <= C; x++) {
            room[1][x - 1] = room[1][x];
        }
        for (int y = 1; y < air_cleaner.first; y++) {
            room[y][C] = room[y + 1][C];
        }
        for (int x = C; x > 2; x--) {
            room[air_cleaner.first][x] = room[air_cleaner.first][x - 1];
        }
        room[air_cleaner.first][2] = 0;

        for (int y = air_cleaner.second + 1; y < R; y++) {
            room[y][1] = room[y + 1][1];
        }
        for (int x = 2; x <= C; x++) {
            room[R][x - 1] = room[R][x];
        }
        for (int y = R; y >= air_cleaner.second + 1; y--) {
            room[y][C] = room[y - 1][C];
        }
        for (int x = C; x > 2; x--) {
            room[air_cleaner.second][x] = room[air_cleaner.second][x - 1];
        }
        room[air_cleaner.second][2] = 0;

        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                if (room[y][x] > 0) {
                    room2[y][x] = room[y][x];
                    q.push({ y, x });
                }
            }
        }

        //cout << "공기청정기가 돌아갑니다. " << '\n';
        //debug_print();
    }

    int sum = 0;
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            if (room[y][x] == -1) continue;
            sum += room[y][x];
        }
    }

    cout << sum;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int dx[4] = { 0, 0, -1, 1 }; // 위 아래 왼 오
int dy[4] = { -1, 1, 0, 0 };
int N, M, k, ti = 0;
vector<int> sea[21][21];
pair<int, int> sea_status[21][21]; 
tuple<int, int, int> s_info[401]; // y좌표 x좌표 방향
int s_priority[401][5][5]; // 우선순위

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> k;
    int temp;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> temp;
            if (temp) {
                sea[y][x].push_back(temp);
                sea_status[y][x] = { temp, k };
                s_info[temp] = { y, x, 0 };
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> temp;
        get<2>(s_info[i]) = temp; // 방향
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> s_priority[i][j][k]; // 1 위 2 아래 3 왼 4 오
            }
        }
    }

    while (ti < 1000) {
        ti++;
        for (int i = 1; i <= M; i++) {
            int cy = get<0>(s_info[i]);
            if (cy == 0) continue;
            int cx = get<1>(s_info[i]);
            int cur_dir = get<2>(s_info[i]);
            bool flag = false;
            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[s_priority[i][cur_dir][dir + 1] - 1];
                int nx = cx + dx[s_priority[i][cur_dir][dir + 1] - 1];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if (sea_status[ny][nx].first == 0 && sea_status[ny][nx].second == 0) {
                    flag = true;
                    sea[cy][cx].erase(remove(sea[cy][cx].begin(), sea[cy][cx].begin(), i), sea[cy][cx].end());
                    sea[ny][nx].push_back(i);
                    get<0>(s_info[i]) = ny;
                    get<1>(s_info[i]) = nx;
                    get<2>(s_info[i]) = s_priority[i][cur_dir][dir + 1];
                    break;
                }
            }
            if (!flag) {
                for (int dir = 0; dir < 4; dir++) {
                    int ny = cy + dy[s_priority[i][cur_dir][dir + 1] - 1];
                    int nx = cx + dx[s_priority[i][cur_dir][dir + 1] - 1];
                    if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                    if (sea_status[ny][nx].first == i) {
                        sea[cy][cx].erase(remove(sea[cy][cx].begin(), sea[cy][cx].begin(), i), sea[cy][cx].end());
                        sea[ny][nx].push_back(i);
                        get<0>(s_info[i]) = ny;
                        get<1>(s_info[i]) = nx;
                        get<2>(s_info[i]) = s_priority[i][cur_dir][dir + 1];
                        break;
                    }
                }
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (sea_status[y][x].second > 0) {
                    sea_status[y][x].second--;
                    if (sea_status[y][x].second == 0) {
                        sea_status[y][x].first = 0;
                    }
                }
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (sea[y][x].size() > 1) {
                    sort(sea[y][x].begin(), sea[y][x].end());
                    int temp = sea[y][x][0];

                    for (int i = 1; i < sea[y][x].size(); i++) {
                        get<0>(s_info[sea[y][x][i]]) = 0;
                        get<1>(s_info[sea[y][x][i]]) = 0;
                        get<2>(s_info[sea[y][x][i]]) = 0;
                    }

                    sea_status[y][x].first = temp;
                    sea_status[y][x].second = k;

                    sea[y][x].clear();
                    sea[y][x].push_back(temp);
                }
                else if (sea[y][x].size() == 1) {
                    sea_status[y][x].first = sea[y][x][0];
                    sea_status[y][x].second = k;
                }
            }
        }

        for (int i = 2; i <= M; i++) {
            if (get<0>(s_info[i]) != 0) {
                break;
            }
            if (i == M) {
                cout << ti;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}
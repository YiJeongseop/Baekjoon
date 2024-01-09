#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, black_cnt = 0, all_cnt = 0, score = 0;
int board[21][21];
int tmp_board[21][21];
bool visited[21][21];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> board[y][x];
            if (board[y][x] == -1) black_cnt++;
        }
    }
    all_cnt = N * N;

    while (all_cnt != black_cnt) {
        for (int y = 1; y <= N; y++) {
            fill(visited[y], visited[y] + 1 + N, false);
        }

        tuple<int, int, int, int, int> info = { 0, 0, 0, 0, 0};
        vector<pair<int, int>> rainbow_v;
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                for (int i = 0; i < rainbow_v.size(); i++) {
                    visited[rainbow_v[i].first][rainbow_v[i].second] = false;
                }
                rainbow_v.clear();
                if (board[y][x] > 0 && !visited[y][x]) {
                    pair<int, int> std_pos = { y, x };
                    int temp_size = 1;
                    int rainbow_cnt = 0;
                    queue<pair<int, int>> q;
                    q.push({ y, x });
                    visited[y][x] = true;
                    int num = board[y][x];
                    //cout << "현재 num은 " << num << "입니다. y : " << y << ", x : " << x << '\n';
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                            if (visited[ny][nx] || board[ny][nx] == -1 || board[ny][nx] == -2)continue;
                            if (board[ny][nx] == num || board[ny][nx] == 0) {
                                if (board[ny][nx] == 0) {
                                    rainbow_v.push_back({ ny, nx });
                                    //cout << ny << ", " << nx << "는 무지개입니다. " << '\n';
                                    rainbow_cnt++;
                                }
                                temp_size++;
                                q.push({ ny, nx });
                                //cout << ny << ", " << nx << "를 방문합니다." << '\n';
                                visited[ny][nx] = true;
                            }
                        }
                    }
                    if (get<0>(info) < temp_size) {
                        info = { temp_size, std_pos.first, std_pos.second, num, rainbow_cnt };
                    }
                    else if (get<0>(info) == temp_size) {
                        if (get<4>(info) < rainbow_cnt) {
                            info = { temp_size, std_pos.first, std_pos.second, num, rainbow_cnt };
                        } 
                        else if (get<4>(info) == rainbow_cnt) {
                            if (get<1>(info) < std_pos.first) {
                                info = { temp_size, std_pos.first, std_pos.second, num, rainbow_cnt };
                            }
                            else if (get<1>(info) == std_pos.first && get<2>(info) < std_pos.second) {
                                info = { temp_size, std_pos.first, std_pos.second, num, rainbow_cnt };
                            }
                        }
                    }
                }
            }
        }

        if (get<0>(info) < 2)break;

        //int a, b, c, d, e;
        //tie(a, b, c, d, e) = info;
        //cout << '\n';
        //cout << a << ", " << b << ", " << c << ", " << d << ", " << e << '\n';
        //cout << '\n';

        for (int y = 1; y <= N; y++) {
            fill(visited[y], visited[y] + 1 + N, false);
        }

        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        v.push_back({ get<1>(info), get<2>(info) });
        q.push({ get<1>(info), get<2>(info) });
        visited[get<1>(info)][get<2>(info)] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if (visited[ny][nx] || board[ny][nx] == -1 || board[ny][nx] == -2)continue;
                if (board[ny][nx] != get<3>(info) && board[ny][nx] != 0) continue;
                q.push({ ny, nx });
                visited[ny][nx] = true;
                v.push_back({ ny, nx });
            }
        }

        int temp = v.size();
        score += (temp * temp);
        //cout << "score에 " << temp * temp << "가 추가되었습니다. " << '\n';
        all_cnt -= temp;
        for (int i = 0; i < v.size(); i++) {
            board[v[i].first][v[i].second] = (-2);
        }


        //cout << "0 중력 작용 전 보드" << '\n';
        //for (int y = 1; y <= N; y++) {
        //    for (int x = 1; x <= N; x++) {
        //        cout << board[y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int x = 1; x <= N; x++) {
            int temp_y = N;
            int temp_cnt = 0;
            while (true) {
                if (board[temp_y][x] == -2 && board[temp_y - 1][x] >= 0) {
                    board[temp_y][x] = board[temp_y - 1][x];
                    board[temp_y - 1][x] = -2;
                    temp_cnt++;
                }
                temp_y--;
                if (temp_y == 1) {
                    temp_y = N;
                    if (temp_cnt == 0) break;
                    temp_cnt = 0;
                }
            }
        }

        //cout << "1 중력 작용 후 보드" << '\n';
        //for (int y = 1; y <= N; y++) {
        //    for (int x = 1; x <= N; x++) {
        //        cout << board[y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                tmp_board[N + 1 - x][y] = board[y][x];
            }
        }
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                board[y][x] = tmp_board[y][x];
            }
        }

        //cout << "2 회전 후 보드" << '\n';
        //for (int y = 1; y <= N; y++) {
        //    for (int x = 1; x <= N; x++) {
        //        cout << board[y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int x = 1; x <= N; x++) {
            int temp_y = N;
            int temp_cnt = 0;
            while (true) {
                if (board[temp_y][x] == -2 && board[temp_y - 1][x] >= 0) {
                    board[temp_y][x] = board[temp_y - 1][x];
                    board[temp_y - 1][x] = -2;
                    temp_cnt++;
                }
                temp_y--;
                if (temp_y == 1) {
                    temp_y = N;
                    if (temp_cnt == 0) break;
                    temp_cnt = 0;
                }
            }
        }

        //cout << "3 중력 작용 후 보드" << '\n';
        //for (int y = 1; y <= N; y++) {
        //    for (int x = 1; x <= N; x++) {
        //        cout << board[y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
    }

    cout << score;

    return 0;
}
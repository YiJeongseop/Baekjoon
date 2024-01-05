#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, fish_count = 0;
int field[20][20];
bool visited[20][20];
int fish[7];
tuple<int, int, int> baby_shark;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool checkForEnd() {
    int shark_size = get<2>(baby_shark);
    if (shark_size > 7) shark_size = 7;
    for (int i = shark_size - 1; i > 0; i--) {
        if (fish[i]) return false;
    }
    return true;
}

bool checkOneFish() {
    int shark_size = get<2>(baby_shark);
    int sum = 0;
    if (shark_size > 7) shark_size = 7;
    for (int i = shark_size - 1; i > 0; i--) {
        sum += fish[i];
    }
    if (sum == 1) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> field[y][x];
            if (field[y][x] == 9) {
                field[y][x] = 0;
                baby_shark = { y, x, 2 };
            }
            else if (field[y][x] != 0) {
                fish[field[y][x]]++;
            }
        }
    }

    int ans = 0;

    while (true) {
        int temp3 = ans;
        if (checkForEnd()) break;

        for (int i = 0; i < N; i++) fill(visited[i], visited[i] + N, false);

        queue<tuple<int, int, int>> q;
        q.push({ get<0>(baby_shark), get<1>(baby_shark), 0 });
        visited[get<0>(baby_shark)][get<1>(baby_shark)] = true;
        if (checkOneFish()) {
            while (!q.empty()) {
                int y, x, time_;
                tie(y, x, time_) = q.front();
                q.pop();
                if (field[y][x] != 0 && field[y][x] < get<2>(baby_shark)) {
                    fish_count++;
                    if (fish_count == get<2>(baby_shark)) {
                        get<2>(baby_shark)++;
                        fish_count = 0;
                    }
                    fish[field[y][x]]--;
                    field[y][x] = 0;
                    get<0>(baby_shark) = y;
                    get<1>(baby_shark) = x;
                    ans += time_;
                    break;
                }
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if (visited[ny][nx] || field[ny][nx] > get<2>(baby_shark)) continue;
                    visited[ny][nx] = true;
                    q.push({ ny, nx, time_ + 1 });
                }
            }
        }
        else {
            bool flag = false;
            int temp = INT_MAX;
            vector<pair<int, int>> v;
            while (!q.empty()) {
                int y, x, time_;
                tie(y, x, time_) = q.front();
                q.pop();
                if (time_ > temp || (time_ == temp && q.empty())) flag = true;
                if (flag) {
                    fish_count++;
                    if (fish_count == get<2>(baby_shark)) {
                        get<2>(baby_shark)++;
                        fish_count = 0;
                    }
                    int temp_y = INT_MAX, temp_x = INT_MAX;
                    for (auto fish_ : v) {
                        if (fish_.first < temp_y) {
                            temp_y = fish_.first;
                            temp_x = fish_.second;
                        }
                        else if (fish_.first == temp_y && fish_.second < temp_x) {
                            temp_y = fish_.first;
                            temp_x = fish_.second;
                        }
                    }
                    fish[field[temp_y][temp_x]]--;
                    field[temp_y][temp_x] = 0;
                    get<0>(baby_shark) = temp_y;
                    get<1>(baby_shark) = temp_x;
                    ans += temp;
                    v.clear();
                    break;
                }
                if (!flag && field[y][x] != 0 && field[y][x] < get<2>(baby_shark)) {
                    temp = time_;
                    v.push_back({ y, x });
                }
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if (visited[ny][nx] || field[ny][nx] > get<2>(baby_shark)) continue;
                    visited[ny][nx] = true;
                    q.push({ ny, nx, time_ + 1 });
                }
            }
            if (!v.empty()) {
                fish_count++;
                if (fish_count == get<2>(baby_shark)) {
                    get<2>(baby_shark)++;
                    fish_count = 0;
                }
                fish[field[v[0].first][v[0].second]]--;
                field[v[0].first][v[0].second] = 0;
                get<0>(baby_shark) = v[0].first;
                get<1>(baby_shark) = v[0].second;
                ans += temp;
            }
        }
        if (temp3 == ans) {
            break;
        }
    }

    cout << ans;

    return 0;
}
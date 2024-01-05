#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M;
int lab[51][51];
int lab2[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                lab[i][j] = 0; // 바이러스
                v.push_back({ i, j });
            }
            else if (lab[i][j] == 1) {
                lab[i][j] = -2; // 벽
            }
            else {
                lab[i][j] = -1; // 빈 칸
            }
        }
    }

    int* mask = new int[v.size()];
    fill(mask, mask + v.size(), 0);

    for (int i = v.size() - 1; i > (int)v.size() - 1 - M; i--) {
        mask[i] = 1;
    }

    int min_ = INT_MAX;

    do {
        queue<pair<int, int>> q;
        queue<tuple<int, int, int>> q2;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                lab2[y][x] = lab[y][x];
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (!mask[i]) {
                lab2[v[i].first][v[i].second] = -3;
            }
            else {
                q.push({ v[i].first, v[i].second });
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if (lab2[ny][nx] == -1) {
                    lab2[ny][nx] = lab2[cur.first][cur.second] + 1;
                    q.push({ ny, nx });
                }
                else if (lab2[ny][nx] == -3) {
                    lab2[ny][nx] = lab2[cur.first][cur.second] + 1;
                    q.push({ ny, nx });
                    // lab2[ny][nx] = 0;
                    q2.push({ ny, nx, lab2[cur.first][cur.second] + 1 });
                }
            }
        }

        int temp4 = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (lab[y][x] == 0 && lab2[y][x] != 0) continue;
                temp4 = max(temp4, lab2[y][x]);
            }
        }

        bool q2_flag = false;
        while (!q2.empty()) {
            auto cur = q2.front();
            q2.pop();
            //if (temp4 == lab2[get<0>(cur)][get<1>(cur)]) {
            //    q2_flag = true;
            //}
            //for (int dir = 0; dir < 4; dir++) {
            //    int ny = get<0>(cur) + dy[dir];
            //    int nx = get<1>(cur) + dx[dir];
            //    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            //    if (lab2[ny][nx] == -1) continue;
            //    if (lab2[ny][nx] >= 0 && lab2[ny][nx] < lab2[get<0>(cur)][get<1>(cur)]) continue;
            //    if(temp4 == )
            //    //if (lab2[ny][nx] == -1) {
            //    //    q2_flag = true;
            //    //    lab2[ny][nx] = get<2>(cur) + 1;
            //    //    q2.push({ ny, nx, lab2[ny][nx] });
            //    //}
            //}
        }

        bool flag = false;
        int max_ = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (lab2[y][x] == -1) {
                    flag = true;
                    break;
                }
                else if (lab[y][x] == 0 && lab2[y][x] != 0) continue;
                max_ = max(max_, lab2[y][x]);
            }
            if (flag) break;
        }
        if (flag) continue;
        if (q2_flag) max_--;
        min_ = min(min_, max_);

        //cout << '\n';
        //for (int i = 0; i < 11; i++) {
        //    for (int j = 0; j < 11; j++) {
        //        cout << lab2[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

    } while (next_permutation(mask, mask + v.size()));

    if (min_ == INT_MAX) cout << -1;
    else cout << min_;

    delete[] mask;

    return 0;
}
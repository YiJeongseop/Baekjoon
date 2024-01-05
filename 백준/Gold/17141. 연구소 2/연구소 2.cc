#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M;
int lab[50][50];
int lab2[50][50];
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

    //cout << v.size() - 1 << '\n';
    //cout << (int)v.size() - 1 - M << '\n';

    for (int i = v.size() - 1; i > (int)v.size() - 1 - M; i--) {
        mask[i] = 1;
    }

    int min_ = INT_MAX;

    do {
        //cout << mask[0] << mask[1] << '\n';

        queue<pair<int, int>> q;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                lab2[y][x] = lab[y][x];
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (!mask[i]) {
                lab2[v[i].first][v[i].second] = -1;
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
                if (lab2[ny][nx] != -1) continue;
                lab2[ny][nx] = lab2[cur.first][cur.second] + 1;
                q.push({ ny, nx });
            }
        }

        //for (int i = 0; i < 5; i++) {
        //    for (int j = 0; j < 5; j++) {
        //        cout << lab2[i][j] << " ";
        //    }
        //    cout << '\n';
        //}

        bool flag = false;
        int max_ = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (lab2[y][x] == -1) {
                    flag = true;
                    break;
                }
                max_ = max(max_, lab2[y][x]);
            }
            if (flag) break;
        }
        if (flag) continue;

        min_ = min(min_, max_);

    } while (next_permutation(mask, mask + v.size()));

    if (min_ == INT_MAX) cout << -1;
    else cout << min_;

    delete[] mask;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, one_cnt = 0;
int lab[8][8];
bool visited[8][8];
pair<int, int> zero_pos[64];
vector<pair<int, int>> two_pos;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int zero_cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> lab[y][x];
            if (lab[y][x] == 0) zero_pos[zero_cnt++] = { y, x };
            else if (lab[y][x] == 2) two_pos.push_back({ y, x });
            else one_cnt++;
        }
    }

    int* mask = new int[zero_cnt];

    for (int i = 0; i < zero_cnt - 3; i++) {
        mask[i] = 0;
    }
    for (int i = zero_cnt - 3; i < zero_cnt; i++) {
        mask[i] = 1;
    }

    int ans = -1;

    do {
        for (int i = 0; i < zero_cnt; i++) {
            if (mask[i]) lab[zero_pos[i].first][zero_pos[i].second] = 1;
        }
        for (int i = 0; i < N; i++) fill(visited[i], visited[i] + M, false);

        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < two_pos.size(); i++) {
            cnt++;
            q.push(two_pos[i]);
            visited[two_pos[i].first][two_pos[i].second] = true;
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.second + dx[dir];
                int ny = cur.first + dy[dir];
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                if (visited[ny][nx] || lab[ny][nx] == 1) continue;
                visited[ny][nx] = true;
                q.push({ ny, nx });
                cnt++;
            }
        }

        ans = max(ans, N * M - one_cnt - 3 - cnt);

        for (int i = 0; i < zero_cnt; i++) {
            if (mask[i]) lab[zero_pos[i].first][zero_pos[i].second] = 0;
        }
    } while (next_permutation(mask, mask + zero_cnt));

    cout << ans;

    delete[] mask;

    return 0;
}
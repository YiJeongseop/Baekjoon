#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int w, h;
string room[20];
int o_to_star[20][20];
int star_to_star[20][20][20][20];
int visited[20][20];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
pair<int, int> start_pos;
vector<pair<int, int>> dirty;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;

    while (!(w == 0 && h == 0)) {
        dirty.clear();
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < 20; k++) {
                    fill(star_to_star[i][j][k], star_to_star[i][j][k] + 20, 0);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            fill(o_to_star[i], o_to_star[i] + w, 0);
            fill(visited[i], visited[i] + w, 0);
            cin >> room[i];
            for (int j = 0; j < w; j++) {
                if (room[i][j] == 'o') start_pos = { i, j };
                else if (room[i][j] == '*') dirty.push_back({ i, j });
            }
        }

        bool flag_minus = false;
        queue<tuple<int, int, int>> q;
        pair<int, int> target_star;
        for (int i = 0; i < dirty.size(); i++) {
            for(int j = 0; j < h; j++)
                fill(visited[j], visited[j] + w, 0);
            target_star = dirty[i];
            visited[start_pos.first][start_pos.second] = 1;
            q.push({start_pos.first, start_pos.second, 0});
            bool flag = false;
            while (!q.empty()) {
                int y, x, dis;
                tie(y, x, dis) = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                    if (visited[ny][nx] || room[ny][nx] == 'x') continue;
                    visited[ny][nx] = true;
                    if (ny == target_star.first && nx == target_star.second) {
                        o_to_star[target_star.first][target_star.second] = dis + 1;
                        flag = true;
                        break;
                    }
                    q.push({ ny, nx, dis + 1 });
                }
                if (flag) {
                    while (!q.empty()) q.pop();
                    break;
                }
            }
            if (o_to_star[target_star.first][target_star.second] == 0) {
                cout << -1 << '\n';
                flag_minus = true;
                break;
            }
        }

        if (flag_minus) {
            cin >> w >> h;
            continue;
        }

        pair<int, int> start_star;
        pair<int, int> end_star;
        for (int i = 0; i < dirty.size(); i++) {
            start_star = dirty[i];
            for (int j = i + 1; j < dirty.size(); j++) {
                for (int j = 0; j < h; j++)
                    fill(visited[j], visited[j] + w, 0);
                end_star = dirty[j];
                queue<tuple<int, int, int>> q2;
                visited[start_star.first][start_star.second] = true;
                q2.push({ start_star.first, start_star.second, 0 });
                bool flag2 = false;
                while (!q2.empty()) {
                    int y, x, dis;
                    tie(y, x, dis) = q2.front();
                    q2.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                        if (visited[ny][nx] || room[ny][nx] == 'x') continue;
                        visited[ny][nx] = true;
                        if (ny == end_star.first && nx == end_star.second) {
                            star_to_star[start_star.first][start_star.second][end_star.first][end_star.second] = dis + 1;
                            star_to_star[end_star.first][end_star.second][start_star.first][start_star.second] = dis + 1;
                            flag2 = true;
                            break;
                        }
                        q2.push({ ny, nx, dis + 1 });
                    }
                    if (flag2) break;
                }
            }
        }

        //cout << " star_to_star ! : " << star_to_star[3][1][1][5] << ", " << star_to_star[3][1][3][5] << ", " << star_to_star[1][5][3][5] << "\n";

        int* mask = new int[dirty.size()];

        for (int i = 0; i < dirty.size(); i++) {
            mask[i] = i;
        }

        int ans = INT_MAX;

        do {
            //for (int i = 0; i < dirty.size(); i++) {
            //    cout << mask[i] << " ";
            //}
            //cout << '\n';
            pair<int, int> start_pos1;
            start_pos1 = dirty[mask[0]];
            int ans2 = o_to_star[start_pos1.first][start_pos1.second];

            //cout << "처음 ans2 값은 " << o_to_star[start_pos1.first][start_pos1.second] << "입니다. " << '\n';

            pair<int, int> temp_pos;

            for (int i = 1; i < dirty.size(); i++) {
                temp_pos = dirty[mask[i]];
                //cout << "temp_pos의 y 값은 " << temp_pos.first << ", x 값은 " << temp_pos.second << "입니다. " << '\n';
                ans2 += star_to_star[start_pos1.first][start_pos1.second][temp_pos.first][temp_pos.second];
                //cout << "현재 ans2 값은 " << ans << "입니다. " << '\n';
                start_pos1 = temp_pos;
            }

            ans = min(ans, ans2);
        } while (next_permutation(mask, mask + (int)dirty.size()));

        cout << ans << '\n';

        delete[] mask;

        cin >> w >> h;
    }

    return 0;
}
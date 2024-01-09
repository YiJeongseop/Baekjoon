#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, island_cnt = 0, ans = INT_MAX;
int board[11][11];
int visited[11][11];
int dis[7][7];
vector<pair<int, int>> island_pos[7];
int dx[4] = { 1, 0, -1, 0 }; // 오 아 왼 위
int dy[4] = { 0, 1, 0, -1 };
int arr[11];

// 드디어 풀었습니다....ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
// 마지막에 if (ans == INT_MAX) cout << -1;를 안 써서 엄청나게 틀렸네요...
// 정말 바보같은 실수네요...
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> board[y][x];
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            if (board[y][x] == 1 && !visited[y][x]) {
                visited[y][x] = true;
                island_cnt++;
                board[y][x] = island_cnt;
                island_pos[island_cnt].push_back({ y, x });
                queue<pair<int, int>> q;
                q.push({ y, x });
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
                        if (visited[ny][nx] || board[ny][nx] == 0) continue;
                        visited[ny][nx] = true;
                        board[ny][nx] = island_cnt;
                        island_pos[island_cnt].push_back({ ny, nx });
                        q.push({ ny, nx });
                    }
                }
            }
        }
    }

    //cout << " 보드 " << '\n';
    //for (int y = 1; y <= N; y++) {
    //    for (int x = 1; x <= M; x++) {
    //        cout << board[y][x] << " ";
    //    }
    //    cout << '\n';
    //}

    for (int y = 1; y <= N; y++)
        fill(visited[y], visited[y] + 1 + M, false);

    for (int i = 1; i <= island_cnt; i++) {
        for (int j = 0; j < island_pos[i].size(); j++) {
            int y, x;
            tie(y, x) = island_pos[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny <= 0 || nx <= 0 || ny > N || nx > M || board[ny][nx] != 0) continue;
                if (dir == 0) { // 오른쪽
                    int cnt = 0;
                    for (int k = nx; k <= M; k++) {
                        cnt++;
                        if (board[ny][k] == i) break;
                        if (board[ny][k] != 0 && board[ny][k] != i) {
                            if (cnt <= 2) break;
                            if (dis[i][board[ny][k]] == 0) dis[i][board[ny][k]] = cnt - 1;
                            else dis[i][board[ny][k]] = min(dis[i][board[ny][k]], cnt - 1);
                            break;
                        }
                    }
                }
                else if (dir == 1) { // 아래쪽
                    int cnt = 0;
                    for (int k = ny; k <= N; k++) {
                        cnt++;
                        if (board[k][nx] == i) break;
                        if (board[k][nx] != 0 && board[k][nx] != i) {
                            if (cnt <= 2) break;
                            if (dis[i][board[k][nx]] == 0) dis[i][board[k][nx]] = cnt - 1;
                            else dis[i][board[k][nx]] = min(dis[i][board[k][nx]], cnt - 1);
                            break;
                        }
                    }
                }
                else if (dir == 2) { // 왼쪽
                    int cnt = 0;
                    for (int k = nx; k > 0; k--) {
                        cnt++;
                        if (board[ny][k] == i) break;
                        if (board[ny][k] != 0 && board[ny][k] != i) {
                            if (cnt <= 2) break;
                            if (dis[i][board[ny][k]] == 0) dis[i][board[ny][k]] = cnt - 1;
                            else dis[i][board[ny][k]] = min(dis[i][board[ny][k]], cnt - 1);
                            break;
                        }
                    }
                }
                else if (dir == 3) { // 위쪽
                    int cnt = 0;
                    for (int k = ny; k > 0; k--) {
                        cnt++;
                        if (board[k][nx] == i) break;
                        if (board[k][nx] != 0 && board[k][nx] != i) {
                            if (cnt <= 2) break;
                            if (dis[i][board[k][nx]] == 0) dis[i][board[k][nx]] = cnt - 1;
                            else dis[i][board[k][nx]] = min(dis[i][board[k][nx]], cnt - 1);
                            break;
                        }
                    }
                }
            }
        }
    }

    vector<tuple<int, int, int>> bridge;
    int bridge_cnt = 0;
    for (int y = 1; y <= island_cnt; y++) {
        for (int x = y + 1; x <= island_cnt; x++) {
            if (dis[y][x] != 0) {
                bridge_cnt++;
                bridge.push_back({ y, x, dis[y][x] });
            } 
        }
    }

    if (bridge_cnt < island_cnt - 1) {
        cout << -1;
        return 0;
    }

    int* mask = new int[bridge_cnt + 2];
    fill(mask, mask + bridge_cnt + 2, 0);
    for (int i = island_cnt - 1; i < bridge_cnt; i++) {
        mask[i] = 1;
    }

    //cout << "bridge_cnt는 " << bridge_cnt << "입니다. " << '\n';

    //cout << "dis" << '\n';
    //for (int y = 1; y <= island_cnt; y++) {
    //    for (int x = 1; x <= island_cnt; x++) {
    //        cout << dis[y][x] << " ";
    //    }
    //    cout << '\n';
    //}

    do {
        //cout << "현재 mask " << '\n';
        //for (int i = 0; i < bridge_cnt; i++) {
        //    cout << mask[i] << " ";
        //}
        //cout << '\n';

        vector<int> v[7];

        for (int i = 1; i <= island_cnt; i++)
            arr[i] = 0;
        int temp = 0;
        for (int i = 0; i < bridge.size(); i++) {
            if (mask[i]) continue;
            int y, x, value;
            tie(y, x, value) = bridge[i];
            temp += value;
            arr[y] = 1;
            arr[x] = 1;
            v[y].push_back(x);
            v[x].push_back(y);
        }

        bool flag = false;
        for (int i = 1; i <= island_cnt; i++) {
            if (arr[i] != 1) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        for (int i = 1; i <= island_cnt; i++)
            arr[i] = 0;
        queue<int> q;
        for (int i = 1; i <= island_cnt; i++) {
            if (v[i].size() != 0) {
                q.push(i);
                arr[i] = 1;
                break;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < v[cur].size(); i++) {
                if (arr[v[cur][i]] == 1) continue;
                arr[v[cur][i]] = 1;
                q.push(v[cur][i]);
            }
        }
        for (int i = 1; i <= island_cnt; i++) {
            if (arr[i] != 1) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        ans = min(temp, ans);

    } while (next_permutation(mask, mask + bridge_cnt));

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    delete[] mask;

    return 0;
}
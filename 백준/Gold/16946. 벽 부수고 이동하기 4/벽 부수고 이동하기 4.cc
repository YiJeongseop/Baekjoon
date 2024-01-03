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
int N, M, original = 2;
int board[1000][1000];
int board2[1000][1000];
pair<int, int> board3[1000][1000];
int visited[1000][1000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < M; x++) {
            board[y][x] = temp[x] - '0';
            board2[y][x] = temp[x] - '0';
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!board[y][x] && !visited[y][x]) {
                original++;
                queue<pair<int, int>> q, q2;
                int cnt = 1;
                visited[y][x] = true;
                board3[y][x].first = original;
                q.push({ y, x });
                q2.push({ y, x });
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.second + dx[dir];
                        int ny = cur.first + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if (visited[ny][nx] || board[ny][nx] == 1) continue;
                        visited[ny][nx] = true;
                        board3[ny][nx].first = original;
                        q.push({ ny, nx });
                        q2.push({ ny, nx });
                        cnt++;
                    }
                }
                while (!q2.empty()) {
                    auto cur = q2.front();
                    q2.pop();
                    board3[cur.first][cur.second].second = cnt;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        fill(visited[i], visited[i] + M, false);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x]) {
                queue<pair<int, int>> q;
                int cnt = 1;
                board[y][x] = 0;
                q.push({ y, x });
                set<int> temp;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.second + dx[dir];
                        int ny = cur.first + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if (board[ny][nx]) continue;
                        if (temp.find(board3[ny][nx].first) == temp.end()) {
                            temp.insert(board3[ny][nx].first);
                            cnt += board3[ny][nx].second;
                        }
                    }
                }
                board2[y][x] = cnt;
                board[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << board2[y][x] % 10;
        }
        cout << '\n';
    }

    return 0;
}
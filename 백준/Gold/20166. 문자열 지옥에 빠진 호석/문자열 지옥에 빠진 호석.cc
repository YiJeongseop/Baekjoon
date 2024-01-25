#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

bool debug_flag = false;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> m;

    int N, M, K;
    string board[10];
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> board[i];

    if (debug_flag) {
        cout << "board" << '\n';
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cout << board[y][x] << " ";
            }
            cout << '\n';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            queue<tuple<string, int, int, int>> q;
            string tmp; tmp += board[i][j];
            q.push({ tmp, 1, i, j});
            m[tmp]++;
            while (!q.empty()) {
                string str;
                int cnt, y, x;
                tie(str, cnt, y, x) = q.front();
                q.pop();
                if (cnt == 6) break;
                for (int dir = 0; dir < 8; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0) ny = N - 1;
                    else if (ny >= N) ny = 0;
                    if (nx < 0) nx = M - 1;
                    else if (nx >= M) nx = 0;
                    string tmp2; tmp2 += str; tmp2 += board[ny][nx];
                    q.push({ tmp2, cnt + 1, ny, nx });
                    if (cnt != 5) m[tmp2]++;
                }
            }
        }
    }

    for (int i = 0; i < K; i++) {
        string tmp;
        cin >> tmp;
        if (m.find(tmp) == m.end()) cout << 0 << '\n';
        else cout << m[tmp] << '\n';
    }

    return 0;
}
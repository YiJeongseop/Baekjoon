#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, Q;
int board[65][65];
int temp[65][65];
int temp2[65][65];
bool visited[65][65];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void rotate(int sy, int sx, int ey, int ex) {
    for (int y = sy; y <= ey; y++) {
        for (int x = sx; x <= ex; x++) {
            //cout << "temp[" << y - sy + 1 << "][" << x - sx + 1 << "] 에 board[" << y << "][" << x << "] 값이 들어갑니다. " << '\n';
            temp[y - sy + 1][x - sx + 1] = board[y][x];
        }
    }

    for (int y = 1; y <= ey - sy + 1; y++) {
        for (int x = 1; x <= ex - sx + 1; x++) {
            //cout << "temp2[" << x << "][" << ey - sy + 2 - y << "] 에 temp[" << y << "][" << x << "] 값이 들어갑니다. " << '\n';
            temp2[x][ey - sy + 2 - y] = temp[y][x];
        }
    }

    for (int y = 1; y <= ey - sy + 1; y++) {
        for (int x = 1; x <= ex - sx + 1; x++) {
            //cout << "board[" << y + sy - 1 << "][" << x + sx - 1 << "] 에 temp2[" << y << "][" << x << "] 값이 들어갑니다. " << '\n';
            board[y + sy - 1][x + sx - 1] = temp2[y][x];
        }
    }

    //cout << '\n';
    //cout << "sy : " << sy << ", sx : " << sx << ", ey : " << ey << ", ex : " << ex << '\n';
    //cout << "현재 보드의 상태" << '\n';
    //for (int y = 1; y <= 8; y++) {
    //    for (int x = 1; x <= 8; x++) {
    //        cout << board[y][x] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    //cout << "현재 temp의 상태" << '\n';
    //for (int y = 1; y <= 8; y++) {
    //    for (int x = 1; x <= 8; x++) {
    //        cout << temp[y][x] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    //cout << "현재 temp2의 상태" << '\n';
    //for (int y = 1; y <= 8; y++) {
    //    for (int x = 1; x <= 8; x++) {
    //        cout << temp2[y][x] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';
    //cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    int full_size = pow(2, N);

    for (int i = 1; i <= full_size; i++) {
        for (int j = 1; j <= full_size; j++) {
            cin >> board[i][j];
        }
    }

    int L;
    for (int i = 0; i < Q; i++) {
        cin >> L;

        if (L != 0) {
            int temp_pow = pow(2, L);
            for (int y = 1; y <= full_size - temp_pow + 1; y += temp_pow) {
                for (int x = 1; x <= full_size - temp_pow + 1; x += temp_pow) {
                    rotate(y, x, y + temp_pow - 1, x + temp_pow - 1);
                }
            }
        }

        //cout << '\n';
        //cout << "현재 보드의 상태" << '\n';
        //for (int y = 1; y <= full_size; y++) {
        //    for (int x = 1; x <= full_size; x++) {
        //        cout << board[y][x] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
        
        for (int y = 1; y <= full_size; y++) {
            for (int x = 1; x <= full_size; x++) {
                temp[y][x] = board[y][x];
            }
        }

        for (int y = 1; y <= full_size; y++) {
            for (int x = 1; x <= full_size; x++) {
                if (board[y][x] == 0) continue;
                int ice_cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny <= 0 || nx <= 0 || ny > full_size || nx > full_size) continue;
                    if (board[ny][nx] > 0) ice_cnt++;
                }
                if (ice_cnt < 3) temp[y][x]--;
            }
        }

        for (int y = 1; y <= full_size; y++) {
            for (int x = 1; x <= full_size; x++) {
                if (temp[y][x] < 0) temp[y][x] = 0;
                board[y][x] = temp[y][x];
            }
        }
    }

    int sum = 0;
    for (int y = 1; y <= full_size; y++) {
        for (int x = 1; x <= full_size; x++) {
            if (board[y][x] <= 0) continue;
            sum += board[y][x];
        }
    }

    int siz = 0;

    //cout << '\n';
    //cout << "현재 보드의 상태" << '\n';
    //for (int y = 1; y <= 8; y++) {
    //    for (int x = 1; x <= 8; x++) {
    //        cout << board[y][x] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    //cout << '\n';
    //cout << "현재 방문 상태" << '\n';
    //for (int y = 1; y <= full_size; y++) {
    //    for (int x = 1; x <= full_size; x++) {
    //        cout << visited[y][x] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    for (int y = 1; y <= full_size; y++) {
        for (int x = 1; x <= full_size; x++) {
            if (board[y][x] == 0 || visited[y][x]) continue;
            int tmp_size = 1;
            queue<pair<int, int>> q;
            q.push({ y, x });
            visited[y][x] = true;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if (ny <= 0 || nx <= 0 || ny > full_size || nx > full_size) continue;
                    if (board[ny][nx] == 0 || visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                    tmp_size++;
                }
            }
            siz = max(siz, tmp_size);
        }
    }

    cout << sum << '\n' << siz;

    return 0;
}
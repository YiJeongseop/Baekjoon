#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[1001][1001];
int arr[1001][1001][11];
int N, M, K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    string temp;
    for (int y = 1; y <= N; y++) {
        cin >> temp;
        for (int x = 1; x <= M; x++) {
            if (temp[x - 1] == '0') board[y][x] = 0;
            else board[y][x] = -1;
        }
    }

    //for (int y = 1; y <= 6; y++) {
    //    for (int x = 1; x <= 4; x++) {
    //        cout << arr[y][x][1];
    //    }
    //    cout << '\n';
    //}

    arr[1][1][K] = 1;
    queue<tuple<int, int, int>> q;
    q.push({ 1, 1, K });
    while (!q.empty()) {
        int y, x, broken;
        tie(y, x, broken) = q.front();

        if (y == N && x == M) {
            cout << arr[y][x][broken];
            return 0;
        }

        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx <= 0 || nx > M || ny <= 0 || ny > N) continue;
            if (arr[ny][nx][broken] > 0) continue;
            if (broken > 0 && board[ny][nx] == -1 && !arr[ny][nx][broken - 1]) {
                arr[ny][nx][broken - 1] = arr[y][x][broken] + 1;
                q.push({ ny, nx, broken - 1 });
            }
            if (board[ny][nx] == -1)continue;
            arr[ny][nx][broken] = arr[y][x][broken] + 1;
            q.push({ ny, nx, broken });
        }
    }

    cout << -1;

    return 0;
}
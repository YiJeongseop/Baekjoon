#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int arr[300][300];
int arr2[300][300];
bool visited[300][300];
int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        fill(visited[y], visited[y] + M, false);
        for (int x = 0; x < M; x++) {
            cin >> arr[y][x];
        }
    }

    int num = 0, count = 0;
    while (true) {
        num = 0;
        queue<pair<int, int>> q;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!visited[y][x] && arr[y][x] > 0) {
                    num++;
                    visited[y][x] = true;
                    q.push({ y, x });
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                            if (arr[ny][nx] <= 0 || visited[ny][nx]) continue;
                            visited[ny][nx] = true;
                            q.push({ ny, nx });
                        }
                    }
                }
            }
        }

        for (int y = 0; y < N; y++) {
            fill(visited[y], visited[y] + M, false);
            for (int x = 0; x < M; x++) {
                arr2[y][x] = arr[y][x];
            }
        }

        if (num == 0) {
            cout << 0;
            return 0;
        }
        else if (num == 1) {
            count++;
            for (int y = 1; y < N - 1; y++) {
                for (int x = 1; x < M - 1; x++) {
                    if (arr[y][x] > 0) {
                        int temp = 0;
                        if (arr2[y - 1][x] <= 0) temp++;
                        if (arr2[y + 1][x] <= 0) temp++;
                        if (arr2[y][x - 1] <= 0) temp++;
                        if (arr2[y][x + 1] <= 0) temp++;
                        arr[y][x] -= temp;
                    }
                }
            }
            continue;
        }
        else {
            break;
        }
    }

    cout << count;

    return 0;
}
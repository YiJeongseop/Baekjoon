#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int arr[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> arr[y][x];
        }
    }

    queue<pair<int, int>> q;

    int new_num = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (arr[y][x] == 1) {
                new_num--;
                arr[y][x] = new_num;
                q.push({ y, x });
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        if (arr[ny][nx] != 1) continue;
                        arr[ny][nx] = new_num;
                        q.push({ ny, nx });
                    }
                }
            }
        }
    }

    int answer = INT_MAX;
    for (int i = -1; i >= new_num; i--) {
        int temp = new_num - i - 1;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (arr[y][x] == temp) {
                    q.push({ y, x });
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                            if (arr[ny][nx] != temp && arr[ny][nx] < 0) {
                                answer = min(arr[cur.first][cur.second], answer);
                            }
                            if (arr[ny][nx] == temp) continue;
                            if (arr[cur.first][cur.second] > 0 && (arr[ny][nx] == 0 || arr[cur.first][cur.second] + 1 < arr[ny][nx])) {
                                arr[ny][nx] = arr[cur.first][cur.second] + 1;
                                q.push({ ny, nx });
                            }
                            else if (arr[cur.first][cur.second] < 0 && arr[ny][nx] != 1) {
                                arr[ny][nx] = 1;
                                q.push({ ny, nx });
                            }
                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}
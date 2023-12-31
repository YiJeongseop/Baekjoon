#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[1001][1001];
int visited[1001][1001];
int S[10];
int arr[10];
int N, M, P;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++)
        cin >> S[i];

    string temp;
    for (int y = 1; y <= N; y++) {
        cin >> temp;
        for (int x = 1; x <= M; x++) {
            if (temp[x - 1] == '.') board[y][x] = 0;
            else if (temp[x - 1] == '#') board[y][x] = -1;
            else board[y][x] = temp[x - 1] - '0';
        }
    }

    while (true) {
        int finish_check = 0;
        for (int player = 1; player <= P; player++) {
            queue<tuple<int, int, int>> q;
            for (int y = 1; y <= N; y++) {
                for (int x = 1; x <= M; x++) {
                    if (board[y][x] == player && !visited[y][x]) {
                        visited[y][x] = 1;
                        arr[player]++;
                        q.push({ y, x, 0 });
                    }
                }
            }
            while (!q.empty()) {
                int y, x, count;
                tie(y, x, count) = q.front();
                q.pop();
                if (count == S[player]) continue;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx <= 0 || nx > M || ny <= 0 || ny > N) continue;
                    if (board[ny][nx] != 0 || visited[ny][nx]) continue;
                    q.push({ ny, nx, count + 1 });
                    board[ny][nx] = player;
                    finish_check++;
                }
            }
        }
        if (!finish_check) {
            break;
        }
    }

    for (int player = 1; player <= P; player++)
        cout << arr[player] << " ";

    return 0;
}
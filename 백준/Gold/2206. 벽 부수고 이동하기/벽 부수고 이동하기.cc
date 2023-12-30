#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int arr1[1000][1000];
int arr2[1000][1000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string temp;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> temp;
        for (int x = 0; x < M; x++) {
            if (temp[x] == '0') {
                arr1[y][x] = arr2[y][x] = 0;
            }
            else {
                arr1[y][x] = arr2[y][x] = -1;
            }
        }
    }

    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }
    
    arr1[0][0] = arr2[0][0] = 1;

    queue<tuple<int, int, bool>> q;
    q.push({ 0, 0, false });
    while (!q.empty()) {
        auto cur = q.front();
        // cout << "현재 q에 들어있는 값은 " << get<0>(cur) << " , " << get<1>(cur) << " ," << get<2>(cur) << " 입니다." << '\n';
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = get<1>(cur) + dx[dir];
            int ny = get<0>(cur) + dy[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (nx == M - 1 && ny == N - 1) {
                if (get<2>(cur)) {
                    cout << arr2[get<0>(cur)][get<1>(cur)] + 1;
                }
                else {
                    cout << arr1[get<0>(cur)][get<1>(cur)] + 1;
                }
                return 0;
            }
            if (!get<2>(cur) && arr1[ny][nx] == -1) {
                arr2[ny][nx] = arr1[get<0>(cur)][get<1>(cur)] + 1;
                q.push({ ny, nx, true });
                continue;
            }
            if (get<2>(cur) && (arr2[ny][nx] != 0 || arr1[ny][nx] != 0)) continue;
            if (!get<2>(cur) && arr1[ny][nx] != 0) continue;
            if (get<2>(cur)) {
                arr2[ny][nx] = arr2[get<0>(cur)][get<1>(cur)] + 1;
                q.push({ ny, nx, true });
            }
            else {
                arr1[ny][nx] = arr1[get<0>(cur)][get<1>(cur)] + 1;
                q.push({ ny, nx, false });
            }
        }
    }

    cout << -1;

    return 0;
}
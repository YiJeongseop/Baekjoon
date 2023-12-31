#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int light[101][101];
int light_check[101][101];
int visited[101][101];
int N, M, ans = 1;
vector<pair<int, int>> map[101][101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        map[x][y].push_back({ a, b });
    }

    light[1][1] = 1;
    visited[1][1] = 1;

    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        //cout << "현재 x : " << x << ", y : " << y << " 방에 있습니다." << '\n';

        //cout << '\n';
        //for (int i = 1; i <= 5; i++) {
        //    for (int j = 1; j <= 5; j++) {
        //        cout << light[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
        
        bool flag = false;
        if (!light_check[x][y]) {
            for (auto other_room : map[x][y]) {
                if (light[other_room.first][other_room.second]) continue;
                //cout << "x : " << x << ", y : " << y << " 방에서 " << other_room.first << ", " << other_room.second << " 방의 불을 밝힙니다. " << '\n';
                light[other_room.first][other_room.second] = 1;
                ans++;
                flag = true;
            }
            light_check[x][y] = 1;
        }
        //cout << '\n';
        //cout << '\n';

        if (flag) {
            for (int i = 1; i <= N; i++) {
                fill(visited[i], visited[i] + N + 1, 0);
            }
            visited[x][y] = true;
            while (!q.empty()) q.pop();
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if (!light[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            //cout << "큐에 " << nx << "와 " << ny << "를 집어넣습니다." << '\n';
            q.push({ nx, ny });
        }
    }

    cout << ans;

    return 0;
}
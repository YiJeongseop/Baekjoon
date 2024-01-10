#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, K;

bool visited[21][21];
int board[21][21];
int board2[21][21];
int dice[6];
int temp[6];
pair<int, int> dice_pos;
int dice_dir = 0;
int dx[4] = { 1, 0, -1, 0 }; //동 남 서 북
int dy[4] = { 0, 1, 0, -1 };

void move(int dir) {
    if (dir == 0) { // 동
        temp[5] = dice[2]; 
        temp[3] = dice[5];
        temp[1] = dice[3];
        temp[2] = dice[1];
        temp[0] = dice[0];
        temp[4] = dice[4];
    }
    else if (dir == 1) { // 남
        temp[5] = dice[0];
        temp[0] = dice[1];
        temp[1] = dice[4];
        temp[4] = dice[5];
        temp[2] = dice[2];
        temp[3] = dice[3];
    }
    else if (dir == 2) { // 서
        temp[3] = dice[1];
        temp[1] = dice[2];
        temp[2] = dice[5];
        temp[5] = dice[3];
        temp[0] = dice[0];
        temp[4] = dice[4];
    }
    else { // 북
        temp[1] = dice[0];
        temp[5] = dice[4];
        temp[0] = dice[5];
        temp[4] = dice[1];
        temp[2] = dice[2];
        temp[3] = dice[3];
    }
    for (int i = 0; i < 6; i++)
        dice[i] = temp[i];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 남 위 동 서 북 밑
    dice[0] = 5; dice[1] = 1; dice[2] = 3; dice[3] = 4; dice[4] = 2; dice[5] = 6;

    cin >> N >> M >> K;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> board[y][x];
        }
    }

    dice_pos.first = 1;
    dice_pos.second = 1;

    int ans = 0;

    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            if (visited[y][x]) continue;
            q.push({ y, x });
            visited[y][x] = true;;
            v.push_back({ y, x });
            int cnt = 1;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
                    if (visited[ny][nx] || board[ny][nx] != board[cur.first][cur.second]) continue;
                    cnt++;
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                    v.push_back({ ny, nx });
                }
            }
            for (int i = 0; i < v.size(); i++) {
                board2[v[i].first][v[i].second] = cnt;
            }
            v.clear();
        }
    }

    for (int i = 0; i < K; i++) {
        int ny = dice_pos.first + dy[dice_dir];
        int nx = dice_pos.second + dx[dice_dir];
        if (ny <= 0 || nx <= 0 || ny > N || nx > M) {
            dice_dir = (dice_dir + 2) % 4;
            ny = dice_pos.first + dy[dice_dir];
            nx = dice_pos.second + dx[dice_dir];
        }

        dice_pos.first = ny;
        dice_pos.second = nx;

        //cout << dice_dir << "방향으로 움직이기 전 주사위" << '\n';
        //for (int i = 0; i < 6; i++)
        //    cout << dice[i] << " ";
        //cout << '\n';

        move(dice_dir);
        ans += board[ny][nx] * board2[ny][nx];

        //cout << dice_dir << "방향으로 움직인 후 주사위" << '\n';
        //for (int i = 0; i < 6; i++)
        //    cout << dice[i] << " ";
        //cout << '\n';

        if (dice[5] > board[ny][nx]) {
            dice_dir = (dice_dir + 1) % 4;
        }
        else if (dice[5] < board[ny][nx]) {
            dice_dir--;
            if (dice_dir == -1) dice_dir = 3;
        }
    }

    cout << ans;

    return 0;
}
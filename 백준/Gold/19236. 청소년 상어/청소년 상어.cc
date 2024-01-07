#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 }; // ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
pair<int, int> fish_pos[17];
pair<int, int> board[5][5];
int ans = 0;

void fish_move() {
    for (int fish_num = 1; fish_num <= 16; fish_num++) {
        if (fish_pos[fish_num].first == 0) continue;
        int f_start_y = fish_pos[fish_num].first;
        int f_start_x = fish_pos[fish_num].second;
        int f_dir = board[f_start_y][f_start_x].second;
        int cnt = 0;
        while (true) {
            if (cnt == 7) break;
            int ny = f_start_y + dy[f_dir - 1];
            int nx = f_start_x + dx[f_dir - 1];
            if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4 || board[ny][nx].first == 20) {
                f_dir += 1;
                if (f_dir == 9) f_dir = 1;
                board[f_start_y][f_start_x].second = f_dir;
                cnt++;
                continue;
            }
            if (board[ny][nx].first == 0 && board[ny][nx].second == 0) {
                board[f_start_y][f_start_x] = { 0, 0 };
                board[ny][nx] = { fish_num, f_dir };
                fish_pos[fish_num] = { ny, nx };
                break;
            }
            else {
                int nxt_fish_num = board[ny][nx].first;
                int nxt_fish_dir = board[ny][nx].second;
                fish_pos[nxt_fish_num] = { f_start_y, f_start_x };
                fish_pos[fish_num] = { ny, nx };
                board[f_start_y][f_start_x] = { nxt_fish_num, nxt_fish_dir };
                board[ny][nx] = { fish_num, f_dir };
                break;
            }
        }
    }
}

//void debug_print() {
//    cout << '\n';
//    cout << "현재 board의 상태" << '\n';
//    for (int y = 1; y <= 4; y++) {
//        for (int x = 1; x <= 4; x++) {
//            cout << board[y][x].first << ", " << board[y][x].second << "   ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    cout << "현재 fish_pos의 상태" << '\n';
//    for (int y = 1; y <= 16; y++) {
//        cout << fish_pos[y].first << ", " << fish_pos[y].second << "  ";
//    }
//    cout << '\n';
//    cout << '\n';
//}

void func(int shark_y, int shark_x, int num_sum, int shark_dir) {
    pair<int, int> temp_board[5][5];
    pair<int, int> temp_pos[17];
    fish_move();

    // debug_print();

    for (int y = 1; y <= 4; y++) {
        for (int x = 1; x <= 4; x++) {
            temp_board[y][x] = board[y][x];
        }
    }

    for (int y = 1; y <= 16; y++) {
        temp_pos[y] = fish_pos[y];
    }
    int ny = shark_y + dy[shark_dir - 1];
    int nx = shark_x + dx[shark_dir - 1];
    queue<pair<int, int>> q;
    while (true) {
        if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4) break;
        if (board[ny][nx].first == 0 && board[ny][nx].second == 0) {
            ny += dy[shark_dir - 1];
            nx += dx[shark_dir - 1];
            continue;
        }
        q.push({ ny, nx });
        ny += dy[shark_dir - 1];
        nx += dx[shark_dir - 1];
    }

    while (!q.empty()) {
        auto nxt_pos = q.front();
        q.pop();
        int temp_num = board[nxt_pos.first][nxt_pos.second].first;
        int temp_dir = board[nxt_pos.first][nxt_pos.second].second; 
        fish_pos[temp_num] = {0, 0};
        board[shark_y][shark_x] = { 0, 0 };
        board[nxt_pos.first][nxt_pos.second].first = 20;
        func(nxt_pos.first, nxt_pos.second, num_sum + temp_num, temp_dir);
        board[nxt_pos.first][nxt_pos.second].first = temp_num;
        board[shark_y][shark_x] = { 20, shark_dir };
        fish_pos[temp_num] = { nxt_pos.first, nxt_pos.second };
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                board[y][x] = temp_board[y][x];
            }
        }
        for (int y = 1; y <= 16; y++) {
            fish_pos[y] = temp_pos[y];
        }
    }

    if (q.empty()) {
        ans = max(ans, num_sum);
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, dir;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> num >> dir;
            board[i][j] = { num, dir };
            fish_pos[num] = { i, j };
        }
    }

    int start_ans = board[1][1].first;
    fish_pos[start_ans] = { 0, 0 };
    int start_dir = board[1][1].second;
    board[1][1] = { 20, start_dir };

    func(1, 1, start_ans, start_dir);

    cout << ans;

    return 0;
}
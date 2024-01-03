#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int N, K, L, ans = 1, len = 1, dir = 0;
int board[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int turn[10001];

//void debug_print() {
//    cout << "현재 ans는 " << ans << "입니다." << '\n';
//    for (int y = 1; y <= N; y++) {
//        for (int x = 1; x <= N; x++) {
//            cout << board[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int temp, temp2;
    for (int i = 0; i < K; i++) {
        cin >> temp >> temp2;
        board[temp][temp2] = 1;
    }

    cin >> L;
    char temp3;
    for (int i = 0; i < L; i++) {
        cin >> temp2 >> temp3;
        if (temp3 == 'D') turn[temp2] = 3; // 오른쪽
        else if (temp3 == 'L') turn[temp2] = 4; // 왼쪽
    }

    deque<pair<int, int>> dq;
    dq.push_front({ 1, 1 });
    board[1][1] = 2;
    while (!dq.empty()) {
        //debug_print();
        if (turn[ans - 1] == 3) {
            dir = (dir + 3) % 4;
        }
        else if (turn[ans - 1] == 4) {
            dir = (dir + 1) % 4;
        }
        int y, x;
        tie(y, x) = dq.front();

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        /*cout << "ny : " << ny << ", nx : " << nx << ", board[ny][nx] : " << board[ny][nx] << "\n";
        cout << '\n';*/
        if (ny <= 0 || nx <= 0 || ny > N || nx > N) break;
        if (board[ny][nx] == 2) break;
        if (board[ny][nx] == 1) len++;
        board[ny][nx] = 2;
        dq.push_front({ ny, nx });
        ans++;
        while (dq.size() != len) {
            board[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
    }

    cout << ans;

    return 0;
}
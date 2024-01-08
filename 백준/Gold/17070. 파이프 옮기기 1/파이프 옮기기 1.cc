#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, cnt = 0;
int board[17][17];

void move(pair<int, int> p1, pair<int, int> p2, int dir) {
    if (dir == 1) {
        if (p2.second + 1 > N || board[p2.first][p2.second + 1] == 1) return;
        if (p2.first == N && p2.second + 1 == N) {
            cnt++;
            return;
        }
        board[p1.first][p1.second] = 0;
        board[p2.first][p2.second + 1] = 2;
        move(p2, { p2.first, p2.second + 1 }, 1);
        move(p2, { p2.first, p2.second + 1 }, 2);
        board[p1.first][p1.second] = 2;
        board[p2.first][p2.second + 1] = 0;
    }
    else if (dir == 2) {
        if (p2.second + 1 > N || p2.first + 1 > N || board[p2.first][p2.second + 1] == 1 || board[p2.first + 1][p2.second + 1] == 1 || board[p2.first + 1][p2.second] == 1)
            return;
        if (p2.first + 1 == N && p2.second + 1 == N) {
            cnt++;
            return;
        }
        board[p1.first][p1.second] = 0;
        board[p2.first][p2.second + 1] = 2;
        board[p2.first + 1][p2.second + 1] = 2;
        board[p2.first + 1][p2.second] = 2;
        move(p2, { p2.first + 1, p2.second + 1 }, 1);
        move(p2, { p2.first + 1, p2.second + 1 }, 2);
        move(p2, { p2.first + 1, p2.second + 1 }, 3);
        board[p1.first][p1.second] = 2;
        board[p2.first][p2.second + 1] = 0;
        board[p2.first + 1][p2.second + 1] = 0;
        board[p2.first + 1][p2.second] = 0;
    }
    else {
        if (p2.first + 1 > N || board[p2.first + 1][p2.second] == 1) return;
        if (p2.first + 1 == N && p2.second == N) {
            cnt++;
            return;
        }
        board[p1.first][p1.second] = 0;
        board[p2.first + 1][p2.second] = 2;
        move(p2, { p2.first + 1, p2.second}, 2);
        move(p2, { p2.first + 1, p2.second}, 3);
        board[p1.first][p1.second] = 2;
        board[p2.first + 1][p2.second] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> board[y][x];
        }
    }
    board[1][1] = board[1][2] = 2;

    move({ 1, 1 }, { 1, 2 }, 1);

    move({ 1, 1 }, { 1, 2 }, 2);

    cout << cnt;

    return 0;
}
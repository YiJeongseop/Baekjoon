#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int paper[500][500];
int N, M, ans = -1;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> paper[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x <= M - 4; x++) {
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y][x + 3]);
        }
    }

    for (int x = 0; x < M; x++) {
        for (int y = 0; y <= N - 4; y++) {
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 3][x]);
        }
    }

    for (int y = 0; y <= N - 2; y++) {
        for (int x = 0; x <= M - 2; x++) {
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y][x + 1] + paper[y + 1][x + 1]);
        }
    }

    for (int y = 0; y <= N - 3; y++) {
        for (int x = 0; x <= M - 2; x++) {
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y][x + 1]);
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 2][x + 1]);
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y + 1][x + 1] + paper[y + 2][x + 1]);
            ans = max(ans, paper[y + 2][x] + paper[y][x + 1] + paper[y + 1][x + 1] + paper[y + 2][x + 1]);
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 2][x + 1]);
            ans = max(ans, paper[y][x + 1] + paper[y + 1][x + 1] + paper[y + 1][x] + paper[y + 2][x]);
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x + 1]);
            ans = max(ans, paper[y][x + 1] + paper[y + 1][x + 1] + paper[y + 2][x + 1] + paper[y + 1][x]);
        }
    }

    for (int y = 0; y <= N - 2; y++) {
        for (int x = 0; x <= M - 3; x++) {
            ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 1][x + 2]);
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x]);
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 2]);
            ans = max(ans, paper[y][x + 2] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 1][x + 2]);
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y + 1][x + 1] + paper[y + 1][x + 2]);
            ans = max(ans, paper[y + 1][x] + paper[y + 1][x + 1] + paper[y][x + 1] + paper[y][x + 2]);
            ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);
            ans = max(ans, paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 1][x + 2] + paper[y][x + 1]);
        }
    }

    cout << ans;

    return 0;
}
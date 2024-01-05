#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, K, year = 0;
int A[11][11];
int nutriment[11][11];
vector<int> tree[11][11];
vector<int> dead[11][11];
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            cin >> A[x][y];
            nutriment[x][y] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while (K--) {
        // 봄
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (tree[x][y].size() != 0) {
                    sort(tree[x][y].begin(), tree[x][y].end());
                    for (int t = 0; t < tree[x][y].size(); t++) {
                        if (nutriment[x][y] < tree[x][y][t]) {
                            int age = tree[x][y][t];
                            tree[x][y].erase(tree[x][y].begin() + t);
                            t--;
                            dead[x][y].push_back(age);
                        }
                        else {
                            nutriment[x][y] -= tree[x][y][t];
                            tree[x][y][t]++;
                        }
                    }
                }
            }
        }

        // 여름
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (dead[x][y].size() != 0) {
                    for (int t = 0; t < dead[x][y].size(); t++) {
                        nutriment[x][y] += (dead[x][y][t] / 2);
                    }
                    dead[x][y].clear();
                }
            }
        }

        // 가을
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (tree[x][y].size() != 0) {
                    for (int t = 0; t < tree[x][y].size(); t++) {
                        if (tree[x][y][t] >= 5 && tree[x][y][t] % 5 == 0) {
                            for (int dir = 0; dir < 8; dir++) {
                                int ny = y + dy[dir];
                                int nx = x + dx[dir];
                                if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
                                tree[nx][ny].push_back(1);
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                nutriment[x][y] += A[x][y];
            }
        }
    }

    int ans = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            ans += tree[x][y].size();
        }
    }
    cout << ans;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M;
int board[51][51];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
vector<pair<int, int>> cloud;

//void debug_print() {
//    cout << " 현재 board 상태 " << '\n';
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

    cin >> N >> M;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> board[y][x];
        }
    }

    cloud.push_back({ N, 1 });
    cloud.push_back({ N, 2 });
    cloud.push_back({ N - 1, 1 });
    cloud.push_back({ N - 1, 2 });

    int d, s;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        
        vector<pair<int, int>> v;
        for (int j = 0; j < cloud.size(); j++) {
            int y, x;
            tie(y, x) = cloud[j];
            for (int k = 0; k < s; k++) {
                y += dy[d - 1];
                x += dx[d - 1];
                if (y <= 0) y = N;
                if (x <= 0) x = N;
                if (y > N) y = 1;
                if (x > N) x = 1;
            }
            board[y][x]++;
            v.push_back({ y , x });
        }

        //cout << "2단계 직후" << '\n';
        //debug_print();

        cloud.clear();

        for (int j = 0; j < v.size(); j++) {
            int y, x;
            tie(y, x) = v[j];
            for (int dir = 1; dir <= 7; dir += 2) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if (board[ny][nx] > 0) board[y][x]++;
            }
        }

        //cout << "4단계 직후" << '\n';
        //debug_print();

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (board[y][x] >= 2) {
                    bool flag = false;
                    for (int j = 0; j < v.size(); j++) {
                        if (v[j].first == y && v[j].second == x) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) continue;

                    cloud.push_back({ y, x });
                    board[y][x] -= 2;
                }
            }
        }

        //cout << "5단계 직후" << '\n';
        //debug_print();
    }

    int ans = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            ans += board[y][x];
        }
    }

    cout << ans;

    return 0;
}
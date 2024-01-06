#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, K, ans = 0;
int board[13][13];
vector<int> horse_board[13][13];
tuple<int, int, int> horse_info[11];
int dx[4] = { 1, -1, 0, 0 }; // 오 왼 위 아래
int dy[4] = { 0, 0, -1, 1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> board[y][x];
        }
    }

    int temp1, temp2, temp3;
    for (int i = 0; i < K; i++) {
        cin >> temp1 >> temp2 >> temp3;
        horse_board[temp1][temp2].push_back(i + 1); // 숫자
        horse_info[i + 1] = { temp1, temp2, temp3 }; // y좌표 x좌표 방향
    }

    while (ans < 1000) {
        ans++;
        //if (ans == 2) {
        //    cout << " debug " << '\n';
        //}
        //cout << ans << "턴 입니다!" << '\n';
        for (int i = 1; i <= K; i++) {
            int hy = get<0>(horse_info[i]);
            int hx = get<1>(horse_info[i]);
            int hdir = get<2>(horse_info[i]);
            int nx = hx + dx[hdir - 1];
            int ny = hy + dy[hdir - 1];
            if (ny <= 0 || nx <= 0 || ny > N || nx > N || board[ny][nx] == 2) {
                if (hdir == 1) hdir = 2;
                else if (hdir == 2)hdir = 1;
                else if (hdir == 3) hdir = 4;
                else hdir = 3;
                get<2>(horse_info[i]) = hdir;
                nx = hx + dx[hdir - 1];
                ny = hy + dy[hdir - 1];
                if (ny <= 0 || nx <= 0 || ny > N || nx > N || board[ny][nx] == 2) continue;
                else if (board[ny][nx] == 1) {
                    for (int j = horse_board[hy][hx].size() - 1; j >= 0; j--) {
                        horse_board[ny][nx].push_back(horse_board[hy][hx][j]);
                        //cout << horse_board[hy][hx][j] << "번 말이 y : " << ny << ", x : " << nx << "로 이동했습니다. " << '\n';
                        get<0>(horse_info[horse_board[hy][hx][j]]) = ny;
                        get<1>(horse_info[horse_board[hy][hx][j]]) = nx;
                        if (horse_board[ny][nx].size() >= 4) {
                            cout << ans;
                            return 0;
                        }
                        if (horse_board[hy][hx][j] == i) {
                            int temp = horse_board[hy][hx].size() - 1;
                            for (int k = temp; k >= j; k--) {
                                horse_board[hy][hx].erase(horse_board[hy][hx].begin() + k);
                            }
                            break;
                        }
                    }
                }
                else {
                    for (int j = 0; j < horse_board[hy][hx].size(); j++) {
                        if (horse_board[hy][hx][j] == i) {
                            for (int k = j; k < horse_board[hy][hx].size(); k++) {
                                horse_board[ny][nx].push_back(horse_board[hy][hx][k]);
                                //cout << horse_board[hy][hx][k] << "번 말이 y : " << ny << ", x : " << nx << "로 이동했습니다. " << '\n';
                                get<0>(horse_info[horse_board[hy][hx][k]]) = ny;
                                get<1>(horse_info[horse_board[hy][hx][k]]) = nx;
                                if (horse_board[ny][nx].size() >= 4) {
                                    cout << ans;
                                    return 0;
                                }
                            }
                            int temp = horse_board[hy][hx].size() - 1;
                            for (int k = temp; k >= j; k--) {
                                horse_board[hy][hx].erase(horse_board[hy][hx].begin() + k);
                            }
                            break;
                        }
                    }
                }
            }
            else if(board[ny][nx] == 1) {
                for (int j = horse_board[hy][hx].size() - 1; j >= 0; j--) {
                    horse_board[ny][nx].push_back(horse_board[hy][hx][j]);
                    //cout << horse_board[hy][hx][j] << "번 말이 y : " << ny << ", x : " << nx << "로 이동했습니다. " << '\n';
                    get<0>(horse_info[horse_board[hy][hx][j]]) = ny;
                    get<1>(horse_info[horse_board[hy][hx][j]]) = nx;
                    if (horse_board[ny][nx].size() >= 4) {
                        cout << ans;
                        return 0;
                    }
                    if (horse_board[hy][hx][j] == i) {
                        int temp = horse_board[hy][hx].size() - 1;
                        for (int k = temp; k >= j; k--) {
                            horse_board[hy][hx].erase(horse_board[hy][hx].begin() + k);
                        }
                        break;
                    }
                }
            }
            else {
                for (int j = 0; j < horse_board[hy][hx].size(); j++) {
                    if (horse_board[hy][hx][j] == i) {
                        for (int k = j; k < horse_board[hy][hx].size(); k++) {
                            horse_board[ny][nx].push_back(horse_board[hy][hx][k]);
                            //cout << horse_board[hy][hx][k] << "번 말이 y : " << ny << ", x : " << nx << "로 이동했습니다. " << '\n';
                            get<0>(horse_info[horse_board[hy][hx][k]]) = ny;
                            get<1>(horse_info[horse_board[hy][hx][k]]) = nx;
                            if (horse_board[ny][nx].size() >= 4) {
                                cout << ans;
                                return 0;
                            }
                        }
                        int temp = horse_board[hy][hx].size() - 1;
                        for (int k = temp; k >= j; k--) {
                            horse_board[hy][hx].erase(horse_board[hy][hx].begin() + k);
                        }
                        break;
                    }
                }
            }
        }

    }

    cout << -1;

    return 0;
}
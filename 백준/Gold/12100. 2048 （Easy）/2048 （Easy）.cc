#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, idx;
int board[20][20];
int board2[20][20];
bool check[20];
int temp[20];
vector<int> temp2;

// dir 0-위 1-왼 2-아 3-오
void func(int dir) {
    if (dir == 0) {
        for (int x = 0; x < N; x++) {
            fill(check, check + N, false);
            fill(temp, temp + N, 0);
            temp2.clear();
            for (int y = 0; y < N; y++) {
                if (board2[y][x]) temp2.push_back(y);
            }
            for (int i = 0; i < temp2.size(); i++) {
                if (i == 0) {
                    idx = 0;
                    temp[i] = board2[temp2[i]][x];
                }
                else if (temp[idx - 1] == board2[temp2[i]][x] && !check[idx - 1]) {
                    temp[idx - 1] *= 2;
                    check[idx - 1] = true;
                    idx--;
                }
                else {
                    temp[idx] = board2[temp2[i]][x];
                }
                idx++;
            }
            for (int i = 0; i < idx; i++) {
                board2[i][x] = temp[i];
            }
            for (int i = idx; i < N; i++) {
                board2[i][x] = 0;
            }
        }
    }
    else if (dir == 1) {
        for (int y = 0; y < N; y++) {
            fill(check, check + N, false);
            fill(temp, temp + N, 0);
            temp2.clear();
            for (int x = 0; x < N; x++) {
                if (board2[y][x]) temp2.push_back(x);
            }
            for (int i = 0; i < temp2.size(); i++) {
                if (i == 0) {
                    idx = 0;
                    temp[i] = board2[y][temp2[i]];
                }
                else if (temp[idx - 1] == board2[y][temp2[i]] && !check[idx - 1]) {
                    temp[idx - 1] *= 2;
                    check[idx - 1] = true;
                    idx--;
                }
                else {
                    temp[idx] = board2[y][temp2[i]];
                }
                idx++;
            }
            for (int i = 0; i < idx; i++) {
                board2[y][i] = temp[i];
            }
            for (int i = idx; i < N; i++) {
                board2[y][i] = 0;
            }
        }
    }
    else if (dir == 2) {
        for (int x = 0; x < N; x++) {
            fill(check, check + N, false);
            fill(temp, temp + N, 0);
            temp2.clear();
            for (int y = N - 1; y >= 0; y--) {
                if (board2[y][x]) {
                    // cout << "board2[" << y << "][" << x << "]에 값이 있습니다." << '\n';
                    temp2.push_back(y);
                    // cout << "temp2 벡터에 " << y << "를 넣었습니다. " << '\n';
                }
            }
            for (int i = 0; i < temp2.size(); i++) {
                if (i == 0) {
                    idx = 0;
                    temp[i] = board2[temp2[i]][x];
                    // cout << "temp[" << i << "]에 " << board2[temp2[i]][x] << "를 넣습니다. " << '\n';
                }
                else if (temp[idx - 1] == board2[temp2[i]][x] && !check[idx - 1]) {
                    // cout << "temp[idx - 1]에 2를 곱하기 전 : " << temp[idx - 1] << '\n';
                    temp[idx - 1] *= 2;
                    // cout << "temp[idx - 1]에 2를 곱한 후 : " << temp[idx - 1] << '\n';
                    check[idx - 1] = true;
                    idx--;
                }
                else {
                    temp[idx] = board2[temp2[i]][x];
                    // cout << "temp[" << idx << "]에 " << board2[temp2[i]][x] << "값을 넣습니다." << '\n';
                }
                idx++;
            }
            // cout << " temp 값을 살펴보겠습니다. " << '\n';
            // cout << temp[0] << " " << temp[1] << " " << temp[2] << '\n';
            for (int i = 0; i < idx; i++) {
                board2[N - 1 - i][x] = temp[i];
                // cout << "board2[" << N - 1 - i << "][" << x << "]에 " << temp[i] << "를 넣습니다!" << '\n';
            }
            for (int i = idx; i < N; i++) {
                board2[N - 1 - i][x] = 0;
            }
        }
    }
    else {
        for (int y = 0; y < N; y++) {
            fill(check, check + N, false);
            fill(temp, temp + N, 0);
            temp2.clear();
            for (int x = N - 1; x >= 0; x--) {
                if (board2[y][x]) temp2.push_back(x);
            }
            for (int i = 0; i < temp2.size(); i++) {
                if (i == 0) {
                    idx = 0;
                    temp[i] = board2[y][temp2[i]];
                }
                else if (temp[idx - 1] == board2[y][temp2[i]] && !check[idx - 1]) {
                    // cout << "temp[idx - 1]에 2를 곱하기 전 : " << temp[idx - 1] << '\n';
                    temp[idx - 1] *= 2;
                    // cout << "temp[idx - 1]에 2를 곱한 후 : " << temp[idx - 1] << '\n';
                    check[idx - 1] = true;
                    idx--;
                }
                else {
                    temp[idx] = board2[y][temp2[i]];
                }
                idx++;
            }
           //  cout << " temp 값을 살펴보겠습니다. " << '\n';
            // cout << temp[0] << " " << temp[1] << " " << temp[2] << '\n';
            for (int i = 0; i < idx; i++) {
                board2[y][N - 1 - i] = temp[i];
            }
            for (int i = idx; i < N; i++) {
                board2[y][N - 1 - i] = 0;
            }
        }
    }
    //if (debug) {
    //    cout << dir << "방향으로 기울였습니다 !!! " << '\n';
    //    for (int i = 0; i < 3; i++) {
    //        for (int j = 0; j < 3; j++) {
    //            cout << board2[i][j] << " ";
    //        }
    //        cout << '\n';
    //    }
    //    cout << '\n';
    //}
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }

    int ans = 0;
    for (int tmp = 0; tmp < 1024; tmp++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                board2[y][x] = board[y][x];
            }
        }
        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            //if ((i == 0 && dir == 3) || (i == 1 && dir == 2) || (i == 2 && dir == 2) || (i == 3 && dir == 3) || (i == 4 && dir == 3)) {
            //    cout << "현재 i는 " << i << "입니다!!" << '\n';
            //    func(dir, true);
            //}
            func(dir);
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                ans = max(ans, board2[y][x]);
            }
        }
    }
    cout << ans;

    return 0;
}
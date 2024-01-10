#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int M, S;
pair<int, int> s_pos;
int caori[5][5];
bool visited[5][5];
vector<int> board[5][5];
vector<int> tmp_board[5][5];
vector<int> tmp_board2[5][5];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int s_dx[4] = { 0, -1, 0, 1 };
int s_dy[4] = { -1, 0, 1, 0 };

void debug_print() {
    cout << "현재 board" << '\n';
    for (int y = 1; y <= 4; y++) {
        for (int x = 1; x <= 4; x++) {
            cout << board[y][x].size() << "마리 ";
        }
        cout << '\n';
    }

    cout << '\n';
    cout << "현재 caori" << '\n';
    for (int y = 1; y <= 4; y++) {
        for (int x = 1; x <= 4; x++) {
            cout << caori[y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> S;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        board[a][b].push_back(c);
    }

    cin >> a >> b;
    s_pos.first = a; s_pos.second = b;

    while (S--) {
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                tmp_board[y][x].clear();
                tmp_board2[y][x].clear();
            }
        }

        // 1단계
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                tmp_board[y][x] = board[y][x];
            }
        }
        
        //cout << "초기 물고기 상태" << '\n';
        //debug_print();

        // 2단계
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                for (int f = 0; f < board[y][x].size(); f++) {
                    int fish_y = y;
                    int fish_x = x;
                    int fish_dir = board[y][x][f];
                    bool flag = false;
                    for (int dir = fish_dir - 1; dir > fish_dir - 9; dir--) {
                        int tmp_dir = dir;
                        if (tmp_dir < 0) {
                            tmp_dir += 8;
                        }
                        int ny = fish_y + dy[tmp_dir];
                        int nx = fish_x + dx[tmp_dir];
                        if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4) continue;
                        if (caori[ny][nx] > 0 || (ny == s_pos.first && nx == s_pos.second)) continue;
                        flag = true;
                        tmp_board2[ny][nx].push_back(tmp_dir + 1);
                        break;
                    }
                    if (!flag) {
                        tmp_board2[fish_y][fish_x].push_back(fish_dir);
                    }
                }
                board[y][x].clear();
            }
        }
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                board[y][x] = tmp_board2[y][x];
            }
        }

        //cout << "물고기 한칸 이동" << '\n';
        //debug_print();

        // 3단계
        int arr[3] = {0, 0, 0};
        int arr2[3] = { 0, 0, 0 };
        int max_val = -1; // ... 0을 조심하세요 ㅠㅠ
        for (int tmp = 0; tmp < 64; tmp++) {
            for (int i = 1; i <= 4; i++)
                fill(visited[i], visited[i] + 5, false);
            int brute = tmp;
            for (int i = 0; i < 3; i++) {
                arr[i] = (brute % 4);
                brute /= 4;
            }
            int fish_cnt = 0;
            int tmp_y = s_pos.first;
            int tmp_x = s_pos.second;
            //if (tmp_y == 1) {
            //    cout << "디버깅" << '\n';
            //}

            bool flag = false;
            for (int i = 0; i < 3; i++) {
                int dir = arr[i];
                if (tmp_y + s_dy[dir] > 4 || tmp_y + s_dy[dir] <= 0 || tmp_x + s_dx[dir] > 4 || tmp_x + s_dx[dir] <= 0) {
                    flag = true;
                    break;
                }
                tmp_y += s_dy[dir];
                tmp_x += s_dx[dir];
                if(!visited[tmp_y][tmp_x]) fish_cnt += board[tmp_y][tmp_x].size();
                visited[tmp_y][tmp_x] = true;
            }
            if (flag) continue;
            //if (tmp_y == 1) {
            //    cout << arr[0] << ", " << arr[1] << ", " << arr[2] << '\n';
            //}
            if (fish_cnt > max_val) {
                max_val = fish_cnt;
                for (int i = 0; i < 3; i++)
                    arr2[i] = arr[i];
            }
            else if (fish_cnt == max_val) {
                if (arr2[0] < arr[0]) continue;
                else if (arr2[0] > arr[0]) {
                    arr2[0] = arr[0];
                    arr2[1] = arr[1];
                    arr2[2] = arr[2];
                    continue;
                }
                if (arr2[1] < arr[1]) continue;
                else if (arr2[1] > arr[1]) {
                    arr2[0] = arr[0];
                    arr2[1] = arr[1];
                    arr2[2] = arr[2];
                    continue;
                }
                if (arr2[2] < arr[2]) continue;
                else if (arr2[2] > arr[2]) {
                    arr2[0] = arr[0];
                    arr2[1] = arr[1];
                    arr2[2] = arr[2];
                    continue;
                }
            }
        }

        // 4단계
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                if (caori[y][x] > 0) caori[y][x]--;
            }
        }

        // 3단계
        s_pos.first += s_dy[arr2[0]];
        s_pos.second += s_dx[arr2[0]];
        if (board[s_pos.first][s_pos.second].size() != 0) {
            caori[s_pos.first][s_pos.second] = 2;
        }
        board[s_pos.first][s_pos.second].clear();

        s_pos.first += s_dy[arr2[1]];
        s_pos.second += s_dx[arr2[1]];
        if (board[s_pos.first][s_pos.second].size() != 0) {
            caori[s_pos.first][s_pos.second] = 2;
        }
        board[s_pos.first][s_pos.second].clear();

        s_pos.first += s_dy[arr2[2]];
        s_pos.second += s_dx[arr2[2]];
        if (board[s_pos.first][s_pos.second].size() != 0) {
            caori[s_pos.first][s_pos.second] = 2;
        }
        board[s_pos.first][s_pos.second].clear();

        
        //cout << arr2[0] << ", " << arr2[1] << ", " << arr2[2] << '\n';
        //cout << "상어 이동" << '\n';
        //cout << "현재 상어의 위치는 " << s_pos.first << ", " << s_pos.second << "입니다. " << '\n';
        //debug_print();

        // 5단계
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                for (int i = 0; i < tmp_board[y][x].size(); i++) {
                    board[y][x].push_back(tmp_board[y][x][i]);
                }
            }
        }

        //cout << "복제 완료" << '\n';
        //debug_print();
        //cout << '\n';
    }

    int ans = 0;
    for (int y = 1; y <= 4; y++) {
        for (int x = 1; x <= 4; x++) {
            ans += board[y][x].size();
        }
    }
    cout << ans;

    return 0;
}
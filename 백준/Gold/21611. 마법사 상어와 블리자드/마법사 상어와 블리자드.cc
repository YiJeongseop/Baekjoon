#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, one = 0, two = 0, three = 0;
int board[50][50];

//void debug_print() {
//    cout << "현재 board 상태입니다." << '\n';
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

    int s_x = (N + 1) / 2;
    int s_y = (N + 1) / 2;

    int d, s;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;

        int temp_x = s_x, temp_y = s_y;
        if (d == 1) { // 위
            for (int j = 0; j < s; j++) {
                temp_y--;
                board[temp_y][temp_x] = 0;
            }
        }
        else if (d == 2) { // 아래
            for (int j = 0; j < s; j++) {
                temp_y++;
                board[temp_y][temp_x] = 0;
            }
        }
        else if (d == 3) { // 왼
            for (int j = 0; j < s; j++) {
                temp_x--;
                board[temp_y][temp_x] = 0;
            }
        }
        else { // 오
            for (int j = 0; j < s; j++) {
                temp_x++;
                board[temp_y][temp_x] = 0;
            }
        }

        //cout << "1. 마법 시전 후" << '\n';
        //debug_print();

        while (true) {
            temp_x = s_x;
            temp_y = s_y;
            int fix_cnt = 2, cnt = 2, fix_cnt2 = 4, cnt2 = 4;
            bool flag = false;
            while (true) {
                cnt--;
                if (cnt >= fix_cnt / 2) {
                    if (fix_cnt % 4 == 0)temp_x++;
                    else temp_x--;
                }
                else {
                    if (fix_cnt % 4 == 0)temp_y--;
                    else temp_y++;
                }

                if (temp_y == 1 && temp_x == 1)break;

                //cout << "temp_y : " << temp_y << ", temp_x : " << temp_x << '\n';
                //cout << "fix_cnt : " << fix_cnt << ", cnt : " << cnt << '\n';
                //cout << "fix_cnt2 : " << fix_cnt2 << ", cnt2 : " << cnt2 << '\n';

                //cout << "현재 fix_cnt는 " << fix_cnt << ", cnt는 " << cnt << ", fix_cnt2는 " << fix_cnt2 << ", cnt2는 " << cnt2 << "입니다. " << '\n';
                if (board[temp_y][temp_x] == 0) {
                    //cout << "temp_y : " << temp_y << ", temp_x : " << temp_x << "가 0입니다. " << '\n';
                    if (temp_y == s_y && temp_x == s_x - 1) {
                        if (board[temp_y][temp_x] == 0 && board[temp_y + 1][temp_x] > 0) flag = true;
                        board[temp_y][temp_x] = board[temp_y + 1][temp_x];
                        board[temp_y + 1][temp_x] = 0;
                        //cout << "temp_y + 1 : " << temp_y + 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                    }
                    else {
                        if (cnt2 >= fix_cnt2 / 2) {
                            if (fix_cnt2 % 4 == 0) {
                                if (board[temp_y][temp_x] == 0 && board[temp_y][temp_x + 1] > 0) flag = true;
                                board[temp_y][temp_x] = board[temp_y][temp_x + 1];
                                board[temp_y][temp_x + 1] = 0;
                                //cout << "temp_y : " << temp_y << ", temp_x + 1 : " << temp_x + 1 << "을 당기겠습니다. " << '\n';
                            }
                            else {
                                if (board[temp_y][temp_x] == 0 && board[temp_y][temp_x - 1] > 0) flag = true;
                                board[temp_y][temp_x] = board[temp_y][temp_x - 1];
                                board[temp_y][temp_x - 1] = 0;
                                //cout << "temp_y : " << temp_y << ", temp_x - 1: " << temp_x - 1 << "을 당기겠습니다. " << '\n';
                            }
                        }
                        else {
                            if (fix_cnt2 % 4 == 0) {
                                if (board[temp_y][temp_x] == 0 && board[temp_y - 1][temp_x] > 0) flag = true;
                                board[temp_y][temp_x] = board[temp_y - 1][temp_x];
                                board[temp_y - 1][temp_x] = 0;
                                //cout << "temp_y - 1 : " << temp_y - 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                            }
                            else {
                                if (board[temp_y][temp_x] == 0 && board[temp_y + 1][temp_x] > 0) flag = true;
                                board[temp_y][temp_x] = board[temp_y + 1][temp_x];
                                board[temp_y + 1][temp_x] = 0;
                                //cout << "temp_y + 1 : " << temp_y + 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                            }
                        }
                    }
                    //cout << "구슬을 당깁니다!!" << '\n';
                    //debug_print();
                }

                if (cnt2 == 0) {
                    cnt2 = fix_cnt2 + 2;
                    fix_cnt2 += 2;
                }
                if (cnt == 0) {
                    cnt = fix_cnt + 2;
                    fix_cnt += 2;
                }
                cnt2--;
            }
            if (!flag) break;
        }

        //cout << "2. 구슬 당긴 후" << '\n';
        //debug_print();

        while (true) {
            vector<pair<int, int>> boom;
            vector<pair<int, int>> boom2;
            int temp_x = s_x, temp_y = s_y;
            int fix_cnt = 2, cnt = 2, num = -1, same_cnt = 0;
            bool flag = false;
            while (true) {
                cnt--;
                if (cnt >= fix_cnt / 2) {
                    if (fix_cnt % 4 == 0)temp_x++;
                    else temp_x--;
                }
                else {
                    if (fix_cnt % 4 == 0)temp_y--;
                    else temp_y++;
                }

                if (num != board[temp_y][temp_x]) {
                    if (board[temp_y][temp_x] == 0) num = -1;
                    else num = board[temp_y][temp_x];
                    same_cnt = 1;
                    boom.clear();
                    boom.push_back({ temp_y, temp_x });
                }
                else {
                    same_cnt++;
                    boom.push_back({ temp_y, temp_x });
                    if (same_cnt == 4) {
                        flag = true;
                        for (int i = 0; i < boom.size(); i++)
                            boom2.push_back(boom[i]);
                    }
                    else if (same_cnt > 4) {
                        boom2.push_back({ temp_y, temp_x });
                    }
                }

                if (temp_y == 1 && temp_x == 1)break;

                if (cnt == 0) {
                    cnt = fix_cnt + 2;
                    fix_cnt += 2;
                }
            }

            if (!flag) break;

            for (int i = 0; i < boom2.size(); i++) {
                if (board[boom2[i].first][boom2[i].second] == 1) one++;
                else if (board[boom2[i].first][boom2[i].second] == 2) two++;
                else if (board[boom2[i].first][boom2[i].second] == 3) three++;
                board[boom2[i].first][boom2[i].second] = 0;
            }

            //cout << "3. 폭발 후" << '\n';
            //debug_print();

            while (true) {
                int temp_x = s_x, temp_y = s_y;
                int fix_cnt = 2, cnt = 2, fix_cnt2 = 4, cnt2 = 4;
                bool flag2 = false;
                while (true) {
                    cnt--;
                    if (cnt >= fix_cnt / 2) {
                        if (fix_cnt % 4 == 0)temp_x++;
                        else temp_x--;
                    }
                    else {
                        if (fix_cnt % 4 == 0)temp_y--;
                        else temp_y++;
                    }

                    if (temp_y == 1 && temp_x == 1) break;

                    if (board[temp_y][temp_x] == 0) {
                        //cout << "temp_y : " << temp_y << ", temp_x : " << temp_x << "가 0입니다. " << '\n';
                        if (temp_y == s_y && temp_x == s_x - 1) {
                            if (board[temp_y][temp_x] == 0 && board[temp_y + 1][temp_x] > 0) flag2 = true;
                            board[temp_y][temp_x] = board[temp_y + 1][temp_x];
                            board[temp_y + 1][temp_x] = 0;
                            //cout << "temp_y + 1 : " << temp_y + 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                        }
                        else {
                            if (cnt2 >= fix_cnt2 / 2) {
                                if (fix_cnt2 % 4 == 0) {
                                    if (board[temp_y][temp_x] == 0 && board[temp_y][temp_x + 1] > 0) flag2 = true;
                                    board[temp_y][temp_x] = board[temp_y][temp_x + 1];
                                    board[temp_y][temp_x + 1] = 0;
                                    //cout << "temp_y : " << temp_y << ", temp_x + 1 : " << temp_x + 1 << "을 당기겠습니다. " << '\n';
                                }
                                else {
                                    if (board[temp_y][temp_x] == 0 && board[temp_y][temp_x - 1] > 0) flag2 = true;
                                    board[temp_y][temp_x] = board[temp_y][temp_x - 1];
                                    board[temp_y][temp_x - 1] = 0;
                                    //cout << "temp_y : " << temp_y << ", temp_x - 1: " << temp_x - 1 << "을 당기겠습니다. " << '\n';
                                }
                            }
                            else {
                                if (fix_cnt2 % 4 == 0) {
                                    if (board[temp_y][temp_x] == 0 && board[temp_y - 1][temp_x] > 0) flag2 = true;
                                    board[temp_y][temp_x] = board[temp_y - 1][temp_x];
                                    board[temp_y - 1][temp_x] = 0;
                                    //cout << "temp_y - 1 : " << temp_y - 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                                }
                                else {
                                    if (board[temp_y][temp_x] == 0 && board[temp_y + 1][temp_x] > 0) flag2 = true;
                                    board[temp_y][temp_x] = board[temp_y + 1][temp_x];
                                    board[temp_y + 1][temp_x] = 0;
                                    //cout << "temp_y + 1 : " << temp_y + 1 << ", temp_x : " << temp_x << "을 당기겠습니다. " << '\n';
                                }
                            }
                        }
                        /*cout << "구슬을 당깁니다!!" << '\n';
                        debug_print();*/
                    }

                    if (cnt2 == 0) {
                        cnt2 = fix_cnt2 + 2;
                        fix_cnt2 += 2;
                    }
                    if (cnt == 0) {
                        cnt = fix_cnt + 2;
                        fix_cnt += 2;
                    }
                    cnt2--;
                }
                if (!flag2) break;
            }

            //cout << "4. 구슬 당긴 후" << '\n';
            //debug_print();
        }

        temp_x = s_x;
        temp_y = s_y;
        int fix_cnt = 2, cnt = 2, num_cnt = 0, num = -1;
        int cnt2 = 0;

        vector<int> nxt_block;

        while (true) {
            cnt2++;
            cnt--;
            if (cnt >= fix_cnt / 2) {
                if (fix_cnt % 4 == 0)temp_x++;
                else temp_x--;
            }
            else {
                if (fix_cnt % 4 == 0)temp_y--;
                else temp_y++;
            }

            if (cnt2 >= N * N) {
                break;
            }

            if (board[temp_y][temp_x] != num) {
                if (num_cnt == 1) {
                    nxt_block.push_back(1);
                }
                else if (num_cnt == 2) {
                    nxt_block.push_back(2);
                }
                else if (num_cnt == 3) {
                    nxt_block.push_back(3);
                }
                if (num == 1) {
                    nxt_block.push_back(1);
                }
                else if (num == 2) {
                    nxt_block.push_back(2);
                }
                else if (num == 3) {
                    nxt_block.push_back(3);
                }
                num = board[temp_y][temp_x];
                num_cnt = 1;
                if (num == 0)break;
            }
            else {
                num_cnt++;
            }

            if (cnt == 0) {
                cnt = fix_cnt + 2;
                fix_cnt += 2;
            }
        }

        temp_x = s_x;
        temp_y = s_y;
        fix_cnt = 2;
        cnt = 2;
        int idx = 0;

        while (true) {
            cnt--;
            if (cnt >= fix_cnt / 2) {
                if (fix_cnt % 4 == 0)temp_x++;
                else temp_x--;
            }
            else {
                if (fix_cnt % 4 == 0)temp_y--;
                else temp_y++;
            }

            if (cnt2 >= N * N || idx >= N * N - 1 || idx >= nxt_block.size())break;

            board[temp_y][temp_x] = nxt_block[idx++];

            if (cnt == 0) {
                cnt = fix_cnt + 2;
                fix_cnt += 2;
            }
        }

        //cout << "마지막 단계" << '\n';
        //debug_print();
    }

    cout << one + 2 * two + 3 * three;

    return 0;
}
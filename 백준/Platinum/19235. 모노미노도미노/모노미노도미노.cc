#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, t, x, y, score = 0; // x 행 y 열
int red[4][4];
int blue[4][6];
int green[6][4];

//void debug_print() {
//    cout << " 빨강 " << '\n';
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            cout << red[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    
//    cout << " 초록 " << '\n';
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 4; j++) {
//            cout << green[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//
//    cout << " 파랑 " << '\n';
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 6; j++) {
//            cout << blue[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

void func_green(int t, int x, int y) {
    if (t == 1) {
        for (int i = 0; i < 5; i++) {
            if (green[i + 1][y] > 0) {
                green[i][y] = 1;
                break;
            }
            if (i == 4) {
                green[5][y] = 1;
            }
        }
    }
    else if (t == 2) {
        for (int i = 0; i < 5; i++) {
            if (green[i + 1][y] > 0 || green[i + 1][y + 1] > 0) {
                green[i][y] = green[i][y + 1] = 2;
                break;
            }
            if (i == 4) {
                green[5][y] = green[5][y + 1] = 2;
            }
        }
    }
    else if (t == 3) {
        for (int i = 1; i < 5; i++) {
            if (green[i + 1][y] > 0) {
                green[i][y] = green[i - 1][y] = 1;
                break;
            }
            if (i == 4) {
                green[5][y] = green[4][y] = 1;
            }
        }
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 5; i > 1; i--) {
            for (int j = 0; j < 4; j++) {
                // cout << "green[" << i << "][" << j << "]은 " << green[i][j] << "입니다. " << '\n';
                if (green[i][j] == 0) break;
                if (j == 3) {
                    flag = true;
                    score++;
                    //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                    for (int k = 0; k < 4; k++) {
                        green[i][k] = 0;
                    }
                    //if (t == 3 && x == 1 && y == 2) {
                    //    cout << "디버그 시작" << '\n';
                    //    debug_print();
                    //}
                }
            }
        }

        bool flag2 = true;
        while (flag2) {
            flag2 = false;
            for (int l = 4; l > 0; l--) {
                for (int k = 0; k < 4; k++) {
                    if (green[l][k] == 1 && green[l + 1][k] == 0) {
                        int temp = l;
                        while (green[temp + 1][k] == 0 && green[temp][k] == 1) {
                            green[temp + 1][k] = 1;
                            green[temp][k] = 0;
                            temp--;
                            flag2 = true;
                            if (temp < 0) break;
                        }
                    }
                    else if (k != 3 && green[l][k] == 2 && green[l][k + 1] == 2 && green[l + 1][k] == 0 && green[l + 1][k + 1] == 0) {
                        int temp = l;
                        while (green[temp + 1][k] == 0 && green[temp + 1][k + 1] == 0 && green[temp][k] == 2 && green[temp][k + 1] == 2) {
                            green[temp + 1][k] = green[temp + 1][k + 1] = 2;
                            green[temp][k] = green[temp][k + 1] = 0;
                            temp--;
                            flag2 = true;
                            if (temp < 0) break;
                        }
                    }
                }
            }
        }

    }

    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] > 0) {
                if (i == 1) {
                    if (green[5][0] > 0 && green[5][1] > 0 && green[5][2] > 0 && green[5][3] > 0) {
                        //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                        score++;
                    }
                    green[5][0] = green[5][1] = green[5][2] = green[5][3] = 0;
                    break;
                }
                if (i == 0) {
                    if (green[4][0] > 0 && green[4][1] > 0 && green[4][2] > 0 && green[4][3] > 0) {
                        //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                        score++;
                    }
                    green[4][0] = green[4][1] = green[4][2] = green[4][3] = 0;
                    break;
                }
            }
        }
    }

    bool flag3 = true;
    while (flag3) {
        flag3 = false;
        for (int l = 4; l >= 0; l--) {
            for (int k = 0; k < 4; k++) {
                if (green[l][k] == 1 && green[l + 1][k] == 0) {
                    int temp = l;
                    while (green[temp + 1][k] == 0 && green[temp][k] == 1) {
                        green[temp + 1][k] = 1;
                        green[temp][k] = 0;
                        temp--;
                        flag3 = true;
                        if (temp < 0) break;
                    }
                }
                else if (k != 3 && green[l][k] == 2 && green[l][k + 1] == 2 && green[l + 1][k] == 0 && green[l + 1][k + 1] == 0) {
                    int temp = l;
                    while (green[temp + 1][k] == 0 && green[temp + 1][k + 1] == 0 && green[temp][k] == 2 && green[temp][k + 1] == 2) {
                        green[temp + 1][k] = green[temp + 1][k + 1] = 2;
                        green[temp][k] = green[temp][k + 1] = 0;
                        temp--;
                        flag3 = true;
                        if (temp < 0) break;
                    }
                }
            }
        }
    }
}

//1 2
void func_blue(int t, int x, int y) {
    if (t == 1) {
        for (int i = 0; i < 5; i++) {
            if (blue[x][i + 1] > 0) {
                blue[x][i] = 1;
                break;
            }
            if (i == 4) {
                blue[x][5] = 1;
            }
        }
    }
    else if (t == 3) {
        for (int i = 0; i < 5; i++) {
            if (blue[x][i + 1] > 0 || blue[x + 1][i + 1] > 0) {
                blue[x][i] = blue[x + 1][i] = 2;
                break;
            }
            if (i == 4) {
                blue[x][5] = blue[x + 1][5] = 2;
            }
        }
    }
    else if (t == 2) {
        for (int i = 1; i < 5; i++) {
            if (blue[x][i + 1] > 0) {
                blue[x][i] = blue[x][i - 1] = 1;
                break;
            }
            if (i == 4) {
                blue[x][5] = blue[x][4] = 1;
            }
        }
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 5; i > 1; i--) {
            for (int j = 0; j < 4; j++) {
                if (blue[j][i] == 0) break;
                if (j == 3) {
                    flag = true;
                    score++;
                    //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                    for (int k = 0; k < 4; k++) {
                        blue[k][i] = 0;
                    }
                }
            }
        }
        bool flag2 = true;
        while (flag2) {
            flag2 = false;
            for (int l = 4; l > 0; l--) {
                for (int k = 0; k < 4; k++) {
                    if (blue[k][l] == 1 && blue[k][l + 1] == 0) {
                        int temp = l;
                        while (blue[k][temp + 1] == 0 && blue[k][temp] == 1) {
                            blue[k][temp + 1] = 1;
                            blue[k][temp] = 0;
                            temp--;
                            flag2 = true;
                            if (temp < 0) break;
                        }
                    }
                    else if (k != 3 && blue[k][l] == 2 && blue[k + 1][l] == 2 && blue[k][l + 1] == 0 && blue[k + 1][l + 1] == 0) {
                        int temp = l;
                        while (blue[k][temp + 1] == 0 && blue[k + 1][temp + 1] == 0 && blue[k][temp] == 2 && blue[k + 1][temp] == 2) {
                            blue[k][temp + 1] = blue[k + 1][temp + 1] = 2;
                            blue[k][temp] = blue[k + 1][temp] = 0;
                            temp--;
                            flag2 = true;
                            if (temp < 0) break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] > 0) {
                if (i == 1) {
                    if (blue[0][5] > 0 && blue[1][5] > 0 && blue[2][5] > 0 && blue[3][5] > 0) {
                        score++;
                        //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                    }
                    blue[0][5] = blue[1][5] = blue[2][5] = blue[3][5] = 0;
                    break;
                }
                if (i == 0) {
                    if (blue[0][4] > 0 && blue[1][4] > 0 && blue[2][4] > 0 && blue[3][4] > 0) {
                        score++;
                        //cout << "score가 1 추가되었습니다. 현재 score는 " << score << "입니다. " << '\n';
                    }
                    blue[0][4] = blue[1][4] = blue[2][4] = blue[3][4] = 0;
                    break;
                }
            }
        }
    }

    bool flag3 = true;
    while (flag3) {
        flag3 = false;
        for (int l = 4; l >= 0; l--) {
            for (int k = 0; k < 4; k++) {
                if (blue[k][l] == 1 && blue[k][l + 1] == 0) {
                    int temp = l;
                    while (blue[k][temp + 1] == 0 && blue[k][temp] == 1) {
                        blue[k][temp + 1] = 1;
                        blue[k][temp] = 0;
                        temp--;
                        flag3 = true;
                        if (temp < 0) break;
                    }
                }
                else if (k != 3 && blue[k][l] == 2 && blue[k + 1][l] == 2 && blue[k][l + 1] == 0 && blue[k + 1][l + 1] == 0) {
                    int temp = l;
                    while (blue[k][temp + 1] == 0 && blue[k + 1][temp + 1] == 0 && blue[k][temp] == 2 && blue[k + 1][temp] == 2) {
                        blue[k][temp + 1] = blue[k + 1][temp + 1] = 2;
                        blue[k][temp] = blue[k + 1][temp] = 0;
                        temp--;
                        flag3 = true;
                        if (temp < 0) break;
                    }
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        for (int j = 0; j < 4; j++)
            fill(red[j], red[j] + 4, 0);
        if (t == 1) {
            red[x][y] = 1;
            func_green(1, x, y);
            func_blue(1, x, y);
        }
        else if (t == 2) {
            red[x][y] = red[x][y + 1] = 1; // 가로
            func_green(2, x, y);
            func_blue(2, x, y);
        }
        else if (t == 3) {
            red[x][y] = red[x + 1][y] = 1; // 세로
            func_green(3, x, y);
            func_blue(3, x, y);
        }

        //cout << "t : " << t << ", x : " << x << ", y : " << y << "를 넣은 후입니다." << '\n';
        //debug_print();
    }

    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cnt += (green[i][j] != 0) + (blue[j][i] != 0);
        }
    }

    cout << score << '\n' << cnt;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int n, ans = 0;
pair<int, char> material[5][11][5][5];
pair<int, char> temp[5][5];
pair<int, char> board[6][6];
int mask[11];

// 1-재료 순서 2-재료 방향 3-재료 위치
void func(int a1, int a2, int a3, int b1, int b2, int b3, int c1, int c2, int c3) {
    // 보드 초기화
    for (int y = 1; y <= 5; y++) {
        for (int x = 1; x <= 5; x++) {
            board[y][x].first = 0;
            board[y][x].second = 'W';
        }
    }

    //cout << a1 << ", " << a2 << ", " << a3 << ", " << b1 << ", " << b2 << ", " << b3 << ", " << c1 << ", " << c2 << ", " << c3 << '\n';

    //cout << "사용할 재료를 출력해봅니다. " << '\n';
    //for (int y = 1; y <= 4; y++) {
    //    for (int x = 1; x <= 4; x++) {
    //        cout << material[a2 + 1][a1][y][x].first << "," << material[a2 + 1][a1][y][x].second << " ";
    //    }
    //    cout << '\n';
    //}

    //for (int y = 1; y <= 4; y++) {
    //    for (int x = 1; x <= 4; x++) {
    //        cout << material[b2 + 1][b1][y][x].first << "," << material[b2 + 1][b1][y][x].second << " ";
    //    }
    //    cout << '\n';
    //}

    //for (int y = 1; y <= 4; y++) {
    //    for (int x = 1; x <= 4; x++) {
    //        cout << material[c2 + 1][c1][y][x].first << "," << material[c2 + 1][c1][y][x].second << " ";
    //    }
    //    cout << '\n';
    //}

    if (a3 == 0) {
        for (int y = 1; y < 5; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[a2 + 1][a1][y][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if(material[a2 + 1][a1][y][x].second != 'W') board[y][x].second = material[a2 + 1][a1][y][x].second;
            }
        }
    }
    else if (a3 == 1) {
        for (int y = 1; y < 5; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[a2 + 1][a1][y][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[a2 + 1][a1][y][x - 1].second != 'W') board[y][x].second = material[a2 + 1][a1][y][x - 1].second;
            }
        }
    }
    else if (a3 == 2) {
        for (int y = 2; y < 6; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[a2 + 1][a1][y - 1][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[a2 + 1][a1][y - 1][x].second != 'W') board[y][x].second = material[a2 + 1][a1][y - 1][x].second;
            }
        }
    }
    else {
        for (int y = 2; y < 6; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[a2 + 1][a1][y - 1][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[a2 + 1][a1][y - 1][x - 1].second != 'W') board[y][x].second = material[a2 + 1][a1][y - 1][x - 1].second;
            }
        }
    }

    if (b3 == 0) {
        for (int y = 1; y < 5; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[b2 + 1][b1][y][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[b2 + 1][b1][y][x].second != 'W') board[y][x].second = material[b2 + 1][b1][y][x].second;
            }
        }
    }
    else if (b3 == 1) {
        for (int y = 1; y < 5; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[b2 + 1][b1][y][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[b2 + 1][b1][y][x - 1].second != 'W') board[y][x].second = material[b2 + 1][b1][y][x - 1].second;
            }
        }
    }
    else if (b3 == 2) {
        for (int y = 2; y < 6; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[b2 + 1][b1][y - 1][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[b2 + 1][b1][y - 1][x].second != 'W') board[y][x].second = material[b2 + 1][b1][y - 1][x].second;
            }
        }
    }
    else {
        for (int y = 2; y < 6; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[b2 + 1][b1][y - 1][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[b2 + 1][b1][y - 1][x - 1].second != 'W') board[y][x].second = material[b2 + 1][b1][y - 1][x - 1].second;
            }
        }
    }

    if (c3 == 0) {
        for (int y = 1; y < 5; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[c2 + 1][c1][y][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[c2 + 1][c1][y][x].second != 'W') board[y][x].second = material[c2 + 1][c1][y][x].second;
            }
        }
    }
    else if (c3 == 1) {
        for (int y = 1; y < 5; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[c2 + 1][c1][y][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[c2 + 1][c1][y][x - 1].second != 'W') board[y][x].second = material[c2 + 1][c1][y][x - 1].second;
            }
        }
    }
    else if (c3 == 2) {
        for (int y = 2; y < 6; y++) {
            for (int x = 1; x < 5; x++) {
                board[y][x].first += material[c2 + 1][c1][y - 1][x].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[c2 + 1][c1][y - 1][x].second != 'W') board[y][x].second = material[c2 + 1][c1][y - 1][x].second;
            }
        }
    }
    else {
        for (int y = 2; y < 6; y++) {
            for (int x = 2; x < 6; x++) {
                board[y][x].first += material[c2 + 1][c1][y - 1][x - 1].first;
                if (board[y][x].first < 0) board[y][x].first = 0;
                else if (board[y][x].first > 9) board[y][x].first = 9;
                if (material[c2 + 1][c1][y - 1][x - 1].second != 'W') board[y][x].second = material[c2 + 1][c1][y - 1][x - 1].second;
            }
        }
    }

    //if (a1 == 2 && a2 == 1 && a3 == 0 && b1 == 3 && b2 == 0 && b3 == 3 && c1 == 1 && c2 == 1 && c3 == 2) {
    //    cout << "디버그 시작" << '\n';
    //    cout << "board" << '\n';
    //    for (int y = 1; y <= 5; y++) {
    //        for (int x = 1; x <= 5; x++) {
    //            cout << board[y][x].first << ", " << board[y][x].second << " ";
    //        }
    //        cout << '\n';
    //    }
    //}

    int r = 0, b = 0, g = 0, y2 = 0, val = 0;
    for (int y = 1; y <= 5; y++) {
        for (int x = 1; x <= 5; x++) {
            if (board[y][x].second == 'W') continue;
            else if (board[y][x].second == 'R') r += board[y][x].first;
            else if (board[y][x].second == 'B') b += board[y][x].first;
            else if (board[y][x].second == 'G') g += board[y][x].first;
            else if (board[y][x].second == 'Y') y2 += board[y][x].first;
        }
    }

    //cout << r << ", " << b << ", " << g << ", " << y2 << '\n';

    val = 7 * r + 5 * b + 3 * g + 2 * y2;
    //cout << "계산 결과 : " << val << '\n';
    //cout << '\n';
    //exit(0);
    ans = max(ans, val);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int effect;
    char element;
    for (int i = 1; i <= n; i++) {
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                cin >> effect;
                material[1][i][y][x].first = effect;
            }
        }
        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 4; x++) {
                cin >> element;
                material[1][i][y][x].second = element;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int y = 1; y <= 4; y++) {
                for (int x = 1; x <= 4; x++) {
                    temp[5 - x][y] = material[j][i][y][x];
                }
            }
            for (int y = 1; y <= 4; y++) {
                for (int x = 1; x <= 4; x++) {
                    material[j + 1][i][y][x] = temp[y][x];
                }
            }
        }
    }

    // 잘 출력되는지 확인
    //for (int i = 1; i <= n; i++) {
    //    cout << i << "번째 재료를 출력합니다." << '\n';
    //    for (int j = 1; j <= 4; j++) {
    //        cout << j - 1 << "번 반시계 방향으로 회전했습니다." << '\n';
    //        for (int y = 1; y <= 4; y++) {
    //            for (int x = 1; x <= 4; x++) {
    //                cout << material[j][i][y][x].first << ", " << material[j][i][y][x].second << "  ";
    //            }
    //            cout << '\n';
    //        }
    //        cout << '\n';
    //    }
    //    cout << '\n';
    //}
    // exit(0);

    fill(mask + 1, mask + n + 1, 0);
    for (int i = n; i > n - 3; i--) {
        mask[i] = 1;
    }

    do {
        //cout << "mask" << '\n';
        //for (int i = 1; i <= n; i++) {
        //    cout << mask[i] << " ";
        //}
        //cout << '\n';
        vector<int> use_num;
        for (int i = 1; i <= n; i++) 
            if (mask[i]) use_num.push_back(i); // 몇 번째 재료를 사용할지 정합니다.

        int arr[3] = {};
        for (int tmp = 0; tmp < 64; tmp++) {
            int brute = tmp;
            for (int i = 0; i < 3; i++) {
                arr[i] = brute % 4; // 재료를 어느 방향으로 돌릴지 정합니다.
                brute /= 4;
            }

            //cout << "arr" << '\n';
            //cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';
            //cout << '\n';

            int arr2[3] = {};
            for (int tmp2 = 0; tmp2 < 64; tmp2++) {
                int brute2 = tmp2;
                for (int i = 0; i < 3; i++) { // 1,1 1,2 2,1 2,2 어디에 붙일지 정합니다.
                    arr2[i] = brute2 % 4;
                    brute2 /= 4;
                }

                //cout << "arr2" << '\n';
                //cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << '\n';
                //cout << '\n';

                func(use_num[0], arr[0], arr2[0], use_num[1], arr[1], arr2[1], use_num[2], arr[2], arr2[2]);
                func(use_num[0], arr[0], arr2[0], use_num[2], arr[1], arr2[1], use_num[1], arr[2], arr2[2]);
                func(use_num[1], arr[0], arr2[0], use_num[2], arr[1], arr2[1], use_num[0], arr[2], arr2[2]);
                func(use_num[1], arr[0], arr2[0], use_num[0], arr[1], arr2[1], use_num[2], arr[2], arr2[2]);
                func(use_num[2], arr[0], arr2[0], use_num[1], arr[1], arr2[1], use_num[0], arr[2], arr2[2]);
                func(use_num[2], arr[0], arr2[0], use_num[0], arr[1], arr2[1], use_num[1], arr[2], arr2[2]);
            }
        }
    } while (next_permutation(mask + 1, mask + n + 1));

    cout << ans;

    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int t, n;
char cube[6][3][3]; // 위w 아래y 앞r 뒤o 왼g 오b

void reset_cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 0) cube[i][j][k] = 'w';
                else if (i == 1) cube[i][j][k] = 'y';
                else if (i == 2) cube[i][j][k] = 'r';
                else if (i == 3) cube[i][j][k] = 'o';
                else if (i == 4) cube[i][j][k] = 'g';
                else if (i == 5) cube[i][j][k] = 'b';
            }
        }
    }
}

void debug_print() {
    cout << " 큐브 위 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[0][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << " 큐브 아래 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[1][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << " 큐브 앞 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[2][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << " 큐브 뒤 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[3][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << " 큐브 왼 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[4][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << " 큐브 오 면의 상태입니다 ! " << '\n';
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << cube[5][y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        reset_cube();
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            char temp[3]; char temp2[3][3];
            if (str[0] == 'U' && str[1] == '+') {
                temp[0] = cube[5][0][0];
                temp[1] = cube[5][0][1];
                temp[2] = cube[5][0][2];
                cube[5][0][0] = cube[3][0][0];
                cube[5][0][1] = cube[3][0][1];
                cube[5][0][2] = cube[3][0][2];
                cube[3][0][0] = cube[4][0][0];
                cube[3][0][1] = cube[4][0][1];
                cube[3][0][2] = cube[4][0][2];
                cube[4][0][0] = cube[2][0][0];
                cube[4][0][1] = cube[2][0][1];
                cube[4][0][2] = cube[2][0][2];
                cube[2][0][0] = temp[0];
                cube[2][0][1] = temp[1];
                cube[2][0][2] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[0][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[0][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'U' && str[1] == '-') {
                temp[0] = cube[5][0][0];
                temp[1] = cube[5][0][1];
                temp[2] = cube[5][0][2];
                cube[5][0][0] = cube[2][0][0];
                cube[5][0][1] = cube[2][0][1];
                cube[5][0][2] = cube[2][0][2];
                cube[2][0][0] = cube[4][0][0];
                cube[2][0][1] = cube[4][0][1];
                cube[2][0][2] = cube[4][0][2];
                cube[4][0][0] = cube[3][0][0];
                cube[4][0][1] = cube[3][0][1];
                cube[4][0][2] = cube[3][0][2];
                cube[3][0][0] = temp[0];
                cube[3][0][1] = temp[1];
                cube[3][0][2] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[0][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[0][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'D' && str[1] == '+') {
                temp[0] = cube[5][2][0];
                temp[1] = cube[5][2][1];
                temp[2] = cube[5][2][2];
                cube[5][2][0] = cube[2][2][0];
                cube[5][2][1] = cube[2][2][1];
                cube[5][2][2] = cube[2][2][2];
                cube[2][2][0] = cube[4][2][0];
                cube[2][2][1] = cube[4][2][1];
                cube[2][2][2] = cube[4][2][2];
                cube[4][2][0] = cube[3][2][0];
                cube[4][2][1] = cube[3][2][1];
                cube[4][2][2] = cube[3][2][2];
                cube[3][2][0] = temp[0];
                cube[3][2][1] = temp[1];
                cube[3][2][2] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[1][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[1][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'D' && str[1] == '-') {
                temp[0] = cube[5][2][0];
                temp[1] = cube[5][2][1];
                temp[2] = cube[5][2][2];
                cube[5][2][0] = cube[3][2][0];
                cube[5][2][1] = cube[3][2][1];
                cube[5][2][2] = cube[3][2][2];
                cube[3][2][0] = cube[4][2][0];
                cube[3][2][1] = cube[4][2][1];
                cube[3][2][2] = cube[4][2][2];
                cube[4][2][0] = cube[2][2][0];
                cube[4][2][1] = cube[2][2][1];
                cube[4][2][2] = cube[2][2][2];
                cube[2][2][0] = temp[0];
                cube[2][2][1] = temp[1];
                cube[2][2][2] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[1][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[1][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'F' && str[1] == '+') {
                temp[0] = cube[0][2][0];
                temp[1] = cube[0][2][1];
                temp[2] = cube[0][2][2];
                cube[0][2][0] = cube[4][2][2];
                cube[0][2][1] = cube[4][1][2];
                cube[0][2][2] = cube[4][0][2];
                cube[4][2][2] = cube[1][2][0];
                cube[4][1][2] = cube[1][2][1];
                cube[4][0][2] = cube[1][2][2];
                cube[1][2][2] = cube[5][2][0];
                cube[1][2][1] = cube[5][1][0];
                cube[1][2][0] = cube[5][0][0];
                cube[5][2][0] = temp[2];
                cube[5][1][0] = temp[1];
                cube[5][0][0] = temp[0];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[2][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[2][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'F' && str[1] == '-') {
                temp[0] = cube[0][2][0];
                temp[1] = cube[0][2][1];
                temp[2] = cube[0][2][2];
                cube[0][2][0] = cube[5][0][0];
                cube[0][2][1] = cube[5][1][0];
                cube[0][2][2] = cube[5][2][0];
                cube[5][2][0] = cube[1][2][2];
                cube[5][1][0] = cube[1][2][1];
                cube[5][0][0] = cube[1][2][0];
                cube[1][2][2] = cube[4][0][2];
                cube[1][2][1] = cube[4][1][2];
                cube[1][2][0] = cube[4][2][2];
                cube[4][0][2] = temp[2];
                cube[4][1][2] = temp[1];
                cube[4][2][2] = temp[0];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[2][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[2][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'B' && str[1] == '+') {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][0][1];
                temp[2] = cube[0][0][2];
                cube[0][0][0] = cube[5][0][2];
                cube[0][0][1] = cube[5][1][2];
                cube[0][0][2] = cube[5][2][2];
                cube[5][2][2] = cube[1][0][2];
                cube[5][1][2] = cube[1][0][1];
                cube[5][0][2] = cube[1][0][0];
                cube[1][0][2] = cube[4][0][0];
                cube[1][0][1] = cube[4][1][0];
                cube[1][0][0] = cube[4][2][0];
                cube[4][2][0] = temp[0];
                cube[4][1][0] = temp[1];
                cube[4][0][0] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[3][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[3][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'B' && str[1] == '-') {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][0][1];
                temp[2] = cube[0][0][2];
                cube[0][0][0] = cube[4][2][0];
                cube[0][0][1] = cube[4][1][0];
                cube[0][0][2] = cube[4][0][0];
                cube[4][2][0] = cube[1][0][0];
                cube[4][1][0] = cube[1][0][1];
                cube[4][0][0] = cube[1][0][2];
                cube[1][0][2] = cube[5][2][2];
                cube[1][0][1] = cube[5][1][2];
                cube[1][0][0] = cube[5][0][2];
                cube[5][0][2] = temp[0];
                cube[5][1][2] = temp[1];
                cube[5][2][2] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[3][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[3][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'L' && str[1] == '+') {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][1][0];
                temp[2] = cube[0][2][0];
                cube[0][0][0] = cube[3][2][2];
                cube[0][1][0] = cube[3][1][2];
                cube[0][2][0] = cube[3][0][2];
                cube[3][2][2] = cube[1][2][2];
                cube[3][1][2] = cube[1][1][2];
                cube[3][0][2] = cube[1][0][2];
                cube[1][0][2] = cube[2][2][0];
                cube[1][1][2] = cube[2][1][0];
                cube[1][2][2] = cube[2][0][0];
                cube[2][2][0] = temp[2];
                cube[2][1][0] = temp[1];
                cube[2][0][0] = temp[0];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[4][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[4][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'L' && str[1] == '-') {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][1][0];
                temp[2] = cube[0][2][0];
                cube[0][0][0] = cube[2][0][0];
                cube[0][1][0] = cube[2][1][0];
                cube[0][2][0] = cube[2][2][0];
                cube[2][2][0] = cube[1][0][2];
                cube[2][1][0] = cube[1][1][2];
                cube[2][0][0] = cube[1][2][2];
                cube[1][0][2] = cube[3][0][2];
                cube[1][1][2] = cube[3][1][2];
                cube[1][2][2] = cube[3][2][2];
                cube[3][0][2] = temp[2];
                cube[3][1][2] = temp[1];
                cube[3][2][2] = temp[0];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[4][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[4][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'R' && str[1] == '+') {
                temp[0] = cube[0][0][2];
                temp[1] = cube[0][1][2];
                temp[2] = cube[0][2][2];
                cube[0][0][2] = cube[2][0][2];
                cube[0][1][2] = cube[2][1][2];
                cube[0][2][2] = cube[2][2][2];
                cube[2][2][2] = cube[1][0][0];
                cube[2][1][2] = cube[1][1][0];
                cube[2][0][2] = cube[1][2][0];
                cube[1][0][0] = cube[3][0][0];
                cube[1][1][0] = cube[3][1][0];
                cube[1][2][0] = cube[3][2][0];
                cube[3][2][0] = temp[0];
                cube[3][1][0] = temp[1];
                cube[3][0][0] = temp[2];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[k][3 - j - 1] = cube[5][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[5][j][k] = temp2[j][k];
                    }
                }
            }
            else if (str[0] == 'R' && str[1] == '-') {
                temp[0] = cube[0][0][2];
                temp[1] = cube[0][1][2];
                temp[2] = cube[0][2][2];
                cube[0][0][2] = cube[3][2][0];
                cube[0][1][2] = cube[3][1][0];
                cube[0][2][2] = cube[3][0][0];
                cube[3][2][0] = cube[1][2][0];
                cube[3][1][0] = cube[1][1][0];
                cube[3][0][0] = cube[1][0][0];
                cube[1][0][0] = cube[2][2][2];
                cube[1][1][0] = cube[2][1][2];
                cube[1][2][0] = cube[2][0][2];
                cube[2][2][2] = temp[2];
                cube[2][1][2] = temp[1];
                cube[2][0][2] = temp[0];
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        temp2[3 - k - 1][j] = cube[5][j][k];
                    }
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[5][j][k] = temp2[j][k];
                    }
                }
            }
            // debug_print();
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
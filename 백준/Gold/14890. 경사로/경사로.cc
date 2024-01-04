#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, L;
int map_[100][100];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map_[y][x];
        }
    }

    int ans = 0;

    bool* arr = new bool[N];

    for (int y = 0; y < N; y++) {
        //cout << "y 인덱스가 " << y << "인 가로줄을 보고 있습니다. " << '\n';
        fill(arr, arr + N, false);
        for (int x = 0; x < N - 1; x++) {
            bool flag = false;
            if (abs(map_[y][x] - map_[y][x + 1]) > 1) break;

            if (map_[y][x] < map_[y][x + 1]) {
                if (L - 1 > x) break;
                int temp = x, cnt = 0;
                if (arr[temp]) {
                    break;
                }
                arr[temp] = true;
                while (true) {
                    if (L != 1 && map_[y][temp - 1] == map_[y][temp]) {
                        if (arr[temp - 1]) {
                            flag = true;
                            break;
                        }
                        arr[temp - 1] = true;
                        cnt++;
                        temp--;
                        if (L - 1 == cnt) {
                            break;
                        }
                    }
                    else if (L == 1) break;
                    else {
                        flag = true;
                        break;
                    }
                }
            }
            else if (map_[y][x] > map_[y][x + 1]) {
                if (N - L <= x) break;
                int temp = x, cnt = 0;
                if (arr[temp + 1]) {
                    break;
                }
                arr[temp + 1] = true;
                while (true) {
                    if (L != 1 && map_[y][temp + 2] == map_[y][temp + 1]) {
                        if (arr[temp + 2]) {
                            flag = true;
                            break;
                        }
                        arr[temp + 2] = true;
                        cnt++;
                        temp++;
                        if (L - 1 == cnt) {
                            if (temp + 2 == N - 1) break;
                            else {
                                if (map_[y][temp + 3] > map_[y][temp + 2]) {
                                    flag = true;
                                    break;
                                }
                                else {
                                    break;
                                }
                            }
                        }
                    }
                    else if (L == 1) {
                        if (arr[temp + 2] > arr[temp + 1]) {
                            flag = true;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) break;

            if (x == N - 2) {
                ans++;
                //cout << "갈 수 있는 길입니다." << '\n';
            }

        }
    }

    for (int x = 0; x < N; x++) {
        //cout << "x 인덱스가 " << x << "인 세로줄을 보고 있습니다. " << '\n';
        //if (x == 1) {
        //    cout << " 디버깅 시작 " << '\n';
        //}
        fill(arr, arr + N, false);
        for (int y = 0; y < N - 1; y++) {
            bool flag = false;
            if (abs(map_[y][x] - map_[y + 1][x]) > 1) break;

            if (map_[y][x] < map_[y + 1][x]) {
                if (L - 1 > y)break;
                int temp = y, cnt = 0;
                if (arr[temp]) {
                    break;
                }
                arr[temp] = true;
                while (true) {
                    if (L != 1 && map_[temp - 1][x] == map_[temp][x]) {
                        if (arr[temp - 1]) {
                            flag = true;
                            break;
                        }
                        arr[temp - 1] = true;
                        cnt++;
                        temp--;
                        if (L - 1 == cnt) {
                            break;
                        }
                    }
                    else if (L == 1) break;
                    else {
                        flag = true;
                        break;
                    }
                }
            }
            else if (map_[y][x] > map_[y + 1][x]) {
                if (N - L <= y)break;
                int temp = y, cnt = 0;
                if (arr[temp + 1]) {
                    break;
                }
                arr[temp + 1] = true;
                while (true) {
                    if (L != 1 && map_[temp + 2][x] == map_[temp + 1][x]) {
                        if (arr[temp + 2]) {
                            flag = true;
                            break;
                        }
                        arr[temp + 2] = true;
                        cnt++;
                        temp++;
                        if (L - 1 == cnt) {
                            if(temp + 2 == N - 1) break;
                            else {
                                if (map_[temp + 3][x] > map_[temp + 2][x]) {
                                    flag = true;
                                    break;
                                }
                                else {
                                    break;
                                }
                            }
                        }
                    }
                    else if (L == 1) {
                        if (arr[temp + 2] > arr[temp + 1]) {
                            flag = true;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) break;

            if (y == N - 2) {
                ans++;
                //cout << "갈 수 있는 길입니다." << '\n';
            }
        }
    }

    cout << ans;

    delete[] arr;
    return 0;
}
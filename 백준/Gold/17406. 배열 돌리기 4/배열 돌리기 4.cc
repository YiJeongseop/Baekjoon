#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, K, ans = INT_MAX;
int arr[51][51];
int arr2[51][51];
vector<tuple<int, int, int>> v;
int mask[6];

void reset_arr2() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            arr2[y][x] = arr[y][x];
        }
    }
}

//void debug_print() {
//    cout << '\n';
//    for (int y = 1; y <= 5; y++) {
//        for (int x = 1; x <= 6; x++) {
//            cout << arr2[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

void rotate(int y1, int x1, int y2, int x2) {
    if (y1 == y2 && x1 == x2) return;
    int temp = arr2[y1][x1];
    for (int y = y1; y < y2; y++) {
        arr2[y][x1] = arr2[y + 1][x1];
    }
    for (int x = x1; x < x2; x++) {
        arr2[y2][x] = arr2[y2][x + 1];
    }
    for (int y = y2; y > y1; y--) {
        arr2[y][x2] = arr2[y - 1][x2];
    }
    for (int x = x2; x > x1; x--) {
        arr2[y1][x] = arr2[y1][x - 1];
    }
    arr2[y1][x1 + 1] = temp;
    rotate(y1 + 1, x1 + 1, y2 - 1, x2 - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> arr[y][x];
        }
    }

    for (int i = 0; i < K; i++) {
        mask[i] = i;
    }

    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({ r, c, s });
    }

    do {
        reset_arr2();
        //cout << "시작 " << '\n';
        //debug_print();

        for (int i = 0; i < K; i++) {
            int r, c, s;
            tie(r, c, s) = v[mask[i]];

            rotate(r - s, c - s, r + s, c + s);
            //cout << "회전 완료" << '\n';
            //debug_print();
        }

        for (int y = 1; y <= N; y++) {
            int temp = 0;
            for (int x = 1; x <= M; x++) {
                temp += arr2[y][x];
            }
            ans = min(ans, temp);
        }

    } while (next_permutation(mask, mask + K));

    cout << ans;

    return 0;
}
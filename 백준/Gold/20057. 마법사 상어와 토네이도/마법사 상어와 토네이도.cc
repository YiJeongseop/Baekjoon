#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, start_y, start_x;
int sand[500][500];
int dy[4][9] = { {1, 0, 0, -1, -2, -1, 0, 0, 1}, {-1, -1, -2, -1, 0, 1, 1, 2, 1}, {-1, 0, 0, 1, 2, 1, 0, 0, -1}, {-1, -1, -2, -1, 0, 1, 1, 2, 1} };
int dx[4][9] = { {1, 1, 2, 1, 0, -1, -1, -2, -1}, {1, 0, 0, -1, -2, -1, 0, 0, 1},{-1, -1, -2, -1, 0, 1, 1, 2, 1}, {-1, 0, 0, 1, 2, 1, 0, 0, -1} };
double per[9] = { 0.01, 0.07, 0.02, 0.1, 0.05, 0.1, 0.07, 0.02, 0.01 };
int dx2[4] = { 0, -1, 0, 1 };
int dy2[4] = { -1, 0, 1, 0 };

//void debug_print() {
//    cout << " sand " << '\n';
//    for (int i = 1; i <= 5; i++) {
//        for (int j = 1; j <= 5; j++) {
//            cout << sand[i][j] << " ";
//        }
//        cout << '\n';
//    }
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    start_y = (N / 2) + 1;
    start_x = (N / 2) + 1;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> sand[y][x];
        }
    }

    int ans = 0;
    int step = 0;
    int i = 2;
    int pre_i = 0;
    int temp_dir = 0;
    bool flag = false;
    while (true) {
        //cout << '\n';
        //cout << "1.현재 위치는 y : " << start_y << ", x : " << start_x << "입니다. " << '\n';
        //cout << "1.현재 step은 " << step << ", i 는 " << i << ", pre_i 는 " << pre_i << ", flag 는 " << flag << "입니다. " << '\n';
        //cout << '\n';
        int nx, ny;
        if (step == i) {
            int temp = i;
            i += (i - pre_i) + 2;
            pre_i = temp;
            flag = !flag;
        }
        if (!flag && (step - pre_i) % (i - pre_i) < (i - pre_i) / 2) {
            nx = start_x - 1;
            ny = start_y;
            temp_dir = 1;
        }
        else if(!flag && (step - pre_i) % (i - pre_i) >= (i - pre_i) / 2){
            nx = start_x;
            ny = start_y + 1; 
            temp_dir = 2;
        }
        else if (flag && (step - pre_i) % (i - pre_i) < (i - pre_i) / 2) {
            nx = start_x + 1;
            ny = start_y;
            temp_dir = 3;
        }
        else if (flag && (step - pre_i) % (i - pre_i) >= (i - pre_i) / 2) {
            nx = start_x;
            ny = start_y - 1; 
            temp_dir = 0;
        }
        //cout << '\n';
        //cout << "2.현재 방향은 " << temp_dir << "이며, ny : " << ny << ", nx : " << nx << "입니다. " << '\n';
        //cout << "2.현재 step은 " << step << ", i 는 " << i << ", pre_i 는 " << pre_i << ", flag 는 " << flag << "입니다. " << '\n';
        //cout << '\n';
        int temp2 = sand[ny][nx];
        int temp3 = 0;
        for (int dir = 0; dir < 9; dir++) {
            int nny = ny + dy[temp_dir][dir];
            int nnx = nx + dx[temp_dir][dir];
            if (nny < 1 || nnx < 1 || nny > N || nnx > N) {
                ans += (int)(temp2 * per[dir]);
                temp3 += (int)(temp2 * per[dir]);
                //cout << "현재 ans 는 " << ans << "입니다. " << '\n';
                continue;
            }
            //cout << "dir : " << dir << ", nny : " << nny << ", nnx : " << nnx << "에 " << (int)(sand[ny][nx] * per[dir]) << "를 더합니다." << '\n';
            sand[nny][nnx] += (int)(sand[ny][nx] * per[dir]);
            temp3 += (int)(sand[ny][nx] * per[dir]);
        }

        //debug_print();

        sand[ny][nx] = 0;
        start_x = nx;
        start_y = ny;
        if (ny + dy2[temp_dir] < 1 || nx + dx2[temp_dir] < 1 || ny + dy2[temp_dir] > N || nx + dx2[temp_dir] > N) {
            ans += temp2 - temp3;
            //cout << "현재 ans 는 " << ans << "입니다. " << '\n';
        }
        else {
            sand[ny + dy2[temp_dir]][nx + dx2[temp_dir]] += temp2 - temp3;
        }

        //debug_print();

        if (nx == 1 && ny == 1) break;

        step++;
    }

    cout << ans;

    return 0;
}
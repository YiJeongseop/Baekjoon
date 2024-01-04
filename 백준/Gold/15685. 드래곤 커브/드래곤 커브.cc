#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int arr[101][101];
int N, x, y, d, g;
int dx[4] = { 1, 0, -1, 0 }; // 동 북 서 남
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        arr[x][y] = 1;
        vector<int> v;
        v.push_back(d);
        for (int j = 1; j <= g; j++) {
            int size_ = v.size();
            for (int k = 1; k <= (1 << j) / 2; k++) {
                v.push_back((v[size_ - k] + 1) % 4);
            }
        }
        int temp_x = x, temp_y = y;
        for (int j = 0; j < v.size(); j++) {
            // cout << temp_x + dx[v[j]] << " <- x좌표 , " << temp_y + dy[v[j]] << " <- y좌표가 1이 됩니다. " << '\n';
            arr[temp_x + dx[v[j]]][temp_y + dy[v[j]]] = 1;
            temp_x += dx[v[j]];
            temp_y += dy[v[j]];
        }
    }

    int ans = 0;
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (arr[x][y] && arr[x + 1][y] && arr[x][y + 1] && arr[x + 1][y + 1]) {
                ans++;
            }
        }
    }

    cout << ans;
    //for (int i = 0; i <= 10; i++) {
    //    for (int j = 0; j <= 10; j++) {
    //        cout << arr[i][j] << " ";
    //    }
    //    cout << '\n';
    //}

    return 0;
}
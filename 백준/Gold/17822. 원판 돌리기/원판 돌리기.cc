#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, M, T;
int circle[51][51];
int temp[50];

void func() {
    int cnt = 0;
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (circle[i][j] == 0) continue;
            else {
                cnt++;
                sum += (double)circle[i][j];
            }
        }
    }
    double avg = sum / cnt;
    //cout << "cnt : " << cnt << ", sum : " << sum << ", avg : " << avg << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (circle[i][j] == 0) continue;
            else if (circle[i][j] < avg) circle[i][j]++;
            else if (circle[i][j] > avg) circle[i][j]--;
        }
    }
}

//void debug_print() {
//    cout << '\n';
//    cout << "현재 원판 수 상태입니다. " << '\n';
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= M; j++) {
//            cout << circle[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> circle[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        if (d == 1) {
            d = 0;
            k = M - k;
        }
        
        for (int j = 1; j <= N; j++) {
            if (j % x == 0) {
                for (int a = 0; a < k; a++) {
                    int temp = circle[j][M];
                    for (int l = M; l > 1; l--) {
                        circle[j][l] = circle[j][l - 1];
                    }
                    circle[j][1] = temp;
                }
            }
        }

        //cout << " 1 " << '\n';
        //debug_print();

        vector<pair<int, int>> v;

        bool flag2 = false;
        for (int j = 1; j <= N; j++) {
            for (int w = 1; w <= M; w++) {
                if (circle[j][w] == 0) continue;
                bool flag = false;
                int temp1 = w - 1;
                if (temp1 == 0) temp1 = M;
                int temp2 = w + 1;
                if (temp2 == M + 1) temp2 = 1;
                if (circle[j][w] == circle[j][temp1]) {
                    flag = true;
                    v.push_back({ j, temp1 });
                }
                if (circle[j][w] == circle[j][temp2]) {
                    flag = true;
                    v.push_back({ j, temp2 });
                }
                if (j != 1 && circle[j][w] == circle[j - 1][w]) {
                    flag = true;
                    v.push_back({ j - 1, w });
                }
                if (j != M && circle[j][w] == circle[j + 1][w]) {
                    flag = true;
                    v.push_back({ j + 1, w });
                }
                if (flag) {
                    v.push_back({ j, w });
                    flag2 = true;
                }
            }
        }

        for (int j = 0; j < v.size(); j++) {
            circle[v[j].first][v[j].second] = 0;
        }

        if (!flag2) {
            func();
        }

        //cout << " 2 " << '\n';
        //debug_print();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += circle[i][j];
        }
    }
    cout << ans;

    return 0;
}
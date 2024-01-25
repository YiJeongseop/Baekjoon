#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> v[1000];
bool debug_flag = false;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans = INT_MAX;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
        sort(v[i].begin(), v[i].end(), greater<int>());
    }

    if (debug_flag) {
        cout << "v" << '\n';
        for (int i = 0; i < N; i++) {
            cout << i << "번 벡터 : ";
            for (int j = 0; j < M; j++) {
                cout << v[i][j] << " ";
            }
            cout << '\n';
        }
    }

    pair<int, int> largest = { 0, v[0][0] }, smallest = { 0, v[0][0] };
    while (v[largest.first].size() > 0) {
        for (int i = 0; i < N; i++) {
            if (v[i][0] > largest.second) {
                largest.first = i;
                largest.second = v[i][0];
                if(debug_flag) cout << "largest.second는 " << v[i][0] << "이 되었습니다. " << '\n';
            }
            else if (v[i][0] < smallest.second) {
                smallest.first = i;
                smallest.second = v[i][0];
                if (debug_flag) cout << "smallest.second는 " << v[i][0] << "이 되었습니다. " << '\n';
            }
        }
        v[largest.first].erase(v[largest.first].begin());
        ans = min(ans, largest.second - smallest.second);
        if (v[largest.first].size() > 0) {
            largest.second = v[largest.first][0];
            if (debug_flag) cout << "largest.second는 " << v[largest.first][0] << "이 되었습니다. " << '\n';
        }

        if (debug_flag) {
            cout << "v" << '\n';
            for (int i = 0; i < N; i++) {
                cout << i << "번 벡터 : ";
                for (int j = 0; j < v[i].size(); j++) {
                    cout << v[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }

    cout << ans;

    return 0;
}
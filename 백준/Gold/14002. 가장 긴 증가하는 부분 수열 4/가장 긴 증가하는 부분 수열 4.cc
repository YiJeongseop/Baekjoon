#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
int arr[1000];
int d[1000][2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    d[0][0] = 0; d[0][1] = 1;

    int ans_idx = 0, ans_cnt = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && d[i][1] <= d[j][1]) {
                flag = false;
                d[i][0] = j;
                d[i][1] = d[j][1] + 1;
                if (d[i][1] > ans_cnt) {
                    ans_cnt = d[i][1];
                    ans_idx = i;
                }
            }
        }
        if (flag) d[i][1] = 1;
    }

    //for (int i = 0; i < N; i++) {
    //    cout << "가리키고 있는 인덱스 : " << d[i][0] << ", 개수 : " << d[i][1] << '\n';
    //}

    if (ans_idx == 0) {
        cout << 1 << '\n' << arr[0];
        return 0;
    }

    vector<int> v;
    for (int i = 0; i < ans_cnt; i++) {
        v.push_back(arr[ans_idx]);
        ans_idx = d[ans_idx][0];
    }

    cout << ans_cnt << '\n';
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";

    return 0;
}
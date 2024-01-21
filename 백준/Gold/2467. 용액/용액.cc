#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

pair<int, int> ans;
int N, val = INT_MAX;
vector<int> v1, v2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) v1.push_back(tmp);
        else v2.push_back(-tmp);
    }

    sort(v2.begin(), v2.end());

    if (v1.size() == 0) {
        cout << -v2[1] << " " << -v2[0];
        return 0;
    }
    else if (v2.size() == 0) {
        cout << v1[0] << " " << v1[1];
        return 0;
    }

    for (int i = 0; i < v1.size(); i++) {
        int st = 0;
        int en = v2.size() - 1;
        while (st <= en) {
            //cout << "st : " << st << ", en : " << en << '\n';
            int mid = (st + en) / 2;
            if (v2[mid] < v1[i]) {
                st = mid + 1;
            }
            else if (v2[mid] > v1[i]) {
                en = mid - 1;
            }
            else {
                cout << -v2[mid] << " " << v1[i];
                return 0;
            }
        }

        //cout << "종료 st : " << st << ", en : " << en << '\n';

        if (st >= v2.size()) {
            if (val > abs(v1[i] - v2[st - 1])) {
                val = abs(v1[i] - v2[st - 1]);
                ans.first = -v2[st - 1];
                ans.second = v1[i];
            }
        }
        else if (st != 0 && abs(v1[i] - v2[st]) > abs(v1[i] - v2[st - 1])) {
            if (val > abs(v1[i] - v2[st - 1])) {
                val = abs(v1[i] - v2[st - 1]);
                ans.first = -v2[st - 1];
                ans.second = v1[i];
            }
        }
        else {
            if (val > abs(v1[i] - v2[st])) {
                val = abs(v1[i] - v2[st]);
                ans.first = -v2[st];
                ans.second = v1[i];
            }
        }
    }

    if (v2.size() >= 2 && abs(ans.second + ans.first) > v2[1] + v2[0]) {
        ans.first = -v2[1];
        ans.second = -v2[0];
    }
    if (v1.size() >= 2 && abs(ans.second + ans.first) > v1[1] + v1[0]) {
        ans.first = v1[0];
        ans.second = v1[1];
    }

    cout << ans.first << " " << ans.second;

    return 0;
}
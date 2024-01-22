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

int N;
int A[1000000];
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 1;
    v.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (v[v.size() - 1] < A[i]) {
            v.push_back(A[i]);
            continue;
        }
        int st = 0, en = v.size() - 1;
        bool flag = false;
        while (st <= en) {
            int mid = (st + en) / 2;
            if (v[mid] > A[i]) {
                flag = true;
                en = mid - 1;
            }
            else if (v[mid] < A[i]) st = mid + 1;
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            v[en + 1] = A[i];
        }
    }

    cout << v.size();

    return 0;
}
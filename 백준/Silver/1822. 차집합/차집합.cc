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
int A[500000];
int B[500000];
int n_a, n_b;

bool binary_search(int target) {
    int st = 0;
    int en = n_b - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (B[mid] < target) st = mid + 1;
        else if (B[mid] > target) en = mid - 1;
        else return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_a >> n_b;

    for (int i = 0; i < n_a; i++) cin >> A[i];
    for (int i = 0; i < n_b; i++) cin >> B[i];

    sort(A, A + n_a);
    sort(B, B + n_b);

    vector<int> v;
    for (int i = 0; i < n_a; i++) {
        if (!binary_search(A[i])) v.push_back(A[i]);
    }
    cout << v.size() << '\n';
    if (v.size() == 0) return 0;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}
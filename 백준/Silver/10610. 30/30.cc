#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string N;

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp = 0;
    bool flag_zero = false;
    vector<int> v;
    for (int i = 0; i < N.length(); i++) {
        if (N[i] - '0' == 0) flag_zero = true;
        tmp += N[i] - '0';
        v.push_back(N[i] - '0');
    }

    if (!flag_zero || tmp % 3 != 0) cout << -1;
    else {
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
            cout << v[i];
    }

    return 0;
}
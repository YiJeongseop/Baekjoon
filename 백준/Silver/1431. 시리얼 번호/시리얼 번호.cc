#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string arr[50];

bool cmp(const string& a, const string& b) {
    if (a.length() == b.length()) {
        int tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                tmp1 += a[i] - '0';
            }
        }
        for (int i = 0; i < b.length(); i++) {
            if (b[i] >= '0' && b[i] <= '9') {
                tmp2 += b[i] - '0';
            }
        }

        if (tmp1 == tmp2) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == b[i]) continue;
                return a[i] < b[i];
            }
        }

        return tmp1 < tmp2;
    }

    return a.length() < b.length();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N, cmp);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}
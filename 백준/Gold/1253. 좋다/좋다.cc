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
using ll = long long;

int arr[10000];
bool check[2000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int lb = lower_bound(arr, arr + N, arr[i] + arr[j]) - arr;
            //cout << "i : " << i << ", j : " << j << ", lb : " << lb << ", arr[" << lb << "] : " << arr[lb] << '\n';
            if (arr[lb] != arr[i] + arr[j]) continue;
            while (!check[lb]) {
                if (lb == i || lb == j) {
                    lb++;
                    continue;
                };
                if (lb >= N) break;
                if (arr[lb] != arr[i] + arr[j]) break;
                check[lb] = true;
                lb++;
                if (lb >= N) break;
                if (arr[lb] != arr[i] + arr[j]) break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += check[i];
    cout << ans;

    return 0;
}
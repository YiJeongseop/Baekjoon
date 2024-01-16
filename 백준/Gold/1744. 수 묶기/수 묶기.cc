#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
int arr[52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    if (N == 1) {
        cout << arr[1];
        return 0;
    }

    sort(arr + 1, arr + N + 1);
    //cout << arr[1] << " " << arr[2] << " " << arr[3] << '\n';
    vector<int> v;

    for (int i = 1; i <= N; i++) {
        if (i != N && arr[i + 1] <= 0) {
            //cout << "v에 " << arr[i] * arr[i + 1] << "이 들어갑니다. " << '\n';
            v.push_back(arr[i] * arr[i + 1]);
            i++;
        }
        else {
            if (i != N && arr[i] == 0 && arr[i + 1] > 0) continue;
            for (int j = N; j >= i; j--) {
                if (i != N - 1 && arr[j - 1] <= 0) {
                    v.push_back(arr[j]);
                    //cout << "v에 " << arr[j] << "이 들어갑니다. " << '\n';
                }
                else if (i == N - 1) {
                    v.push_back(arr[j]);
                    //cout << "v에 " << arr[j] << "이 들어갑니다. " << '\n';
                }
                else {
                    if (arr[j] >= 1 && arr[j - 1] == 1) {
                        v.push_back(arr[j]);
                        continue;
                    }
                    //cout << "v에 " << arr[j] * arr[j - 1] << "이 들어갑니다. " << '\n';
                    v.push_back(arr[j] * arr[j - 1]);
                    j--;
                }
            }
            break;
        }
    }

    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i];
    }
    cout << ans;

    return 0;
}
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int arr[200001];
int N, K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    fill(arr, arr + 200001, -1);

    queue<int> q;
    arr[N] = 0;
    q.push(N);

    bool flag = false;
    int ans = 0;
    int time = INT_MAX;

    while (!q.empty()) {
        int cur = q.front();
        // cout << '\n';
        // cout << "현재 cur는 " << cur << "입니다. " << '\n';
        if (cur == K && !flag) {
            cout << arr[cur] << '\n';
            time = arr[cur];
            ans++;
            flag = true;
        }
        else if (cur == K && flag) {
            ans++;
        }
        else if (arr[cur] > time) {
            break;
        }
        q.pop();

        if (cur - 1 >= 0 && (arr[cur - 1] == -1 || arr[cur - 1] >= arr[cur] + 1)) {
            // cout << cur - 1 << "에 " << arr[cur] + 1 << "값을 넣었습니다." << '\n';
            arr[cur - 1] = arr[cur] + 1;
            q.push(cur - 1);
        }

        if (cur + 1 <= 100000 && (arr[cur + 1] == -1 || arr[cur + 1] >= arr[cur] + 1)) {
            // cout << cur + 1 << "에 " << arr[cur] + 1 << "값을 넣었습니다." << '\n';
            arr[cur + 1] = arr[cur] + 1;
            q.push(cur + 1);
        }

        if (cur * 2 <= 200000 && (arr[cur * 2] == -1 || arr[cur * 2] >= arr[cur] + 1)) {
            // cout << cur * 2 << "에 " << arr[cur] + 1 << "값을 넣었습니다." << '\n';
            arr[cur * 2] = arr[cur] + 1;
            q.push(cur * 2);
        }
    }

    cout << ans;

    return 0;
}
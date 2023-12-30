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
    while (!q.empty()) {
        int cur = q.front();
        if (cur == K) {
            cout << arr[cur];
            return 0;
        }
        q.pop();
        
        if (cur - 1 >= 0 && (arr[cur - 1] == -1 || arr[cur - 1] > arr[cur] + 1)) {
            arr[cur - 1] = arr[cur] + 1;
            q.push(cur - 1);
        }

        if (cur + 1 <= 100000 && (arr[cur + 1] == -1 || arr[cur + 1] > arr[cur] + 1)) {
            arr[cur + 1] = arr[cur] + 1;
            q.push(cur + 1);
        }

        if (cur * 2 <= 200000 && (arr[cur * 2] == -1 || arr[cur * 2] > arr[cur])) {
            arr[cur * 2] = arr[cur];
            q.push(cur * 2);
        }
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int arr[200001];
int record[200001];
int N, K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    queue<int> q;
    stack<int> s;
    q.push(N);
    arr[N] = 1;
    record[N] = -1;
    while (!q.empty()) {
        int cur = q.front();
        if (cur == K) {
            cout << arr[cur] - 1 << '\n';

            int temp = record[K];
            while (temp != -1) {
                s.push(temp);
                temp = record[temp];
            }
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << K;

            return 0;
        }
        q.pop();

        if (cur * 2 <= 200000 && !arr[cur * 2]) {
            record[cur * 2] = cur;
            arr[cur * 2] = arr[cur] + 1;
            q.push(cur * 2);
        }

        if (cur - 1 >= 0 && !arr[cur - 1]) {
            record[cur - 1] = cur;
            arr[cur - 1] = arr[cur] + 1;
            q.push(cur - 1);
        }

        if (cur + 1 <= 100000 && !arr[cur + 1]) {
            record[cur + 1] = cur;
            arr[cur + 1] = arr[cur] + 1;
            q.push(cur + 1);
        }
    }

    return 0;
}
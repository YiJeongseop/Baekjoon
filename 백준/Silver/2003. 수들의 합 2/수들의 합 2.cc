#include <iostream>

using namespace std;

int arr[10000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int en = 0, sum = arr[0];
    for (int st = 0; st < N; st++) {
        while (en < N && sum < M) {
            en++;
            if (en != N) sum += arr[en];
        }
        if (en == N) break;
        if (sum == M) ans++;
        sum -= arr[st];
    }

    cout << ans;

    return 0;
}
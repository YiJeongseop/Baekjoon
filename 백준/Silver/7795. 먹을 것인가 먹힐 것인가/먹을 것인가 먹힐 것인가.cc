#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int T;
int A[20000];
int B[20000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(A, A + N);
        sort(B, B + M);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i] > B[j]) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
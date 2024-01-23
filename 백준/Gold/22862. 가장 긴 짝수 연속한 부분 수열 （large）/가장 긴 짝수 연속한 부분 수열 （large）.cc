#include <iostream>

using namespace std;

int arr[1'000'000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];

    int en = 0, jump_cnt = 0, ans = 0;
    for (int st = 0; st < N; st++) {
        while (en < N) {
            if (arr[en] % 2 == 1) {
                if (jump_cnt == K) {
                    ans = max(ans, en - st - jump_cnt);
                    break;
                }
                jump_cnt++;
            }
            en++;
        }
        //cout << "st : " << st << ", en : " << en << ", jump_cnt : " << jump_cnt <<'\n';
        if (en == N) {
            ans = max(ans, en - st - jump_cnt);
            break;
        }
        if (arr[st] % 2 == 1) jump_cnt--;
    }
    cout << ans;

    return 0;
}
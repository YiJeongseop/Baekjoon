#include <iostream>

using namespace std;

int arr[200000];
int overlap[200000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];

    int en = 0, ans = 0;
    for (int st = 0; st < N; st++) {
        while (en < N) {
            //cout << "st : " << st << ", en : " << en << ", overlap[" << arr[en] << "] : " << overlap[arr[en]] << '\n';
            if (overlap[arr[en]] >= K) {
                ans = max(ans, en - st);
                break;
            }
            overlap[arr[en]]++;
            en++;
        }
        if (en == N) {
            ans = max(ans, en - st);
            break;
        }
        overlap[arr[st]]--;
        //cout << "overlap[" << arr[st] << "]에서 1을 뺐습니다. 뺀 후의 값 : " << overlap[arr[st]] << '\n';
    }
    
    cout << ans;

    return 0;
}
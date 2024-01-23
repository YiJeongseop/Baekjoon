#include <iostream>
#include <set>

using namespace std;
using ll = long long;
bool debug_flag = false;

ll arr[60006];
ll arr2[3006];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, d, k, c;
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[N + i] = arr[i];
    }
    N *= 2;

    if (debug_flag) {
        cout << "배열" << '\n';
        for (int i = 0; i < N; i++) cout << arr[i] << " ";
        cout << '\n';
        cout << '\n';
    }

    set<ll> s;
    ll en = 0, ans = 0;
    s.insert(arr[0]);
    arr2[arr[0]] = 1;
    for (int st = 0; st < N; st++) {
        if (debug_flag) cout << "===============================================" << '\n';
        if(debug_flag) cout << "st : " << st << " 시작" << '\n';
        while (en < N) {
            if (en - st + 1 == k) break;
            en++;
            if (en != N) {
                arr2[arr[en]]++;
                if (debug_flag) cout << "arr2[" << arr[en] << "]에 1이 더해졌습니다. 현재 값 : " << arr2[arr[en]] << '\n';
                if (arr2[arr[en]] == 1) {
                    if (debug_flag) cout << arr[en] << "을 s에 넣습니다." << '\n';
                    s.insert(arr[en]);
                }
                if (s.size() > ans) ans = s.size();
            }
        }
        if (arr2[c] == 0) ans = max(ans, (ll)s.size() + 1);
        if (en == N) break;
        if (debug_flag) {
            cout << "en : " << en << ", s.size() : " << s.size() << '\n';
            cout << "s" << '\n';
            for (auto i : s) cout << i << " ";
            cout << '\n';
        }
        arr2[arr[st]]--;
        if (debug_flag) cout << "arr2[" << arr[st] << "]에 1이 빼졌습니다. 현재 값 : " << arr2[arr[st]] << '\n';
        if (arr2[arr[st]] == 0) s.erase(arr[st]);
        if (debug_flag) cout << "===============================================" << '\n';
    }

    cout << ans;

    return 0;
}
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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int debug_cnt = 0;
    bool debug_flag = false, debug_flag_just_ans = false;
    ll B, A = 1, ten = 1, pre_b = -1;
    cin >> B;

    ll ans[10] = { 0, };
    if (B < 10) {
        cout << 0 << " ";
        for (int i = 1; i <= B; i++)
            cout << 1 << " ";
        for (int i = B + 1; i < 10; i++)
            cout << 0 << " ";
        return 0;
    }

    ll origin_b = B;

    while (B) {
        debug_cnt++;
        if (debug_flag) cout << '\n' << "---------------------시작-------------------" << '\n' << "현재 A는 " << A << " 입니다." << '\n';

        ans[0] -= ten;

        if (debug_flag) cout << "ans[0] 값 : " << ans[0] << ", ten : " << ten << '\n' << '\n';

        // pre_b = B % 10;

        if (debug_flag) cout << "pre_b 값 : " << pre_b << ", B : " << B << '\n' << '\n';

        ll tmp_b = B % 10;

        while (B % 10 != 9) {
            B++;

            if (debug_flag) cout << "B는 " << B << "이 되었습니다." << '\n' << "ans[" << B % 10 << "] 값 : " << ans[B % 10] << '\n';
            
            ans[B % 10] -= ten;
            
            if (debug_flag) cout << ten << "이 빼진 후 ans[" << B % 10 << "] 값 : " << ans[B % 10] << '\n' << '\n';
        }

        if (debug_flag) {
            cout << '\n';
            cout << "1. ans 상태" << '\n';
            for (int i = 0; i < 10; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }

        for (int i = 0; i < 10; i++)
            ans[i] += (B / 10 + 1) * ten;

        if (debug_flag) {
            cout << '\n';
            cout << "2. ans 상태" << '\n';
            for (int i = 0; i < 10; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }

        A /= 10;

        if (debug_flag) cout << "A는 10으로 나뉘어져서 " << A << "가 되었습니다." << '\n';

        B /= 10;

        if (debug_flag) cout << "B는 10으로 나뉘어져서 " << B << "가 되었습니다." << '\n';

        if (B == 0) {
            ans[tmp_b] -= ten - 1 - pre_b;
            break;
        }

        if(pre_b != -1) ans[tmp_b] -= ten - 1 - pre_b;

        if (debug_flag) cout << "pre_b 값 : " << pre_b << ", ten : " << ten << '\n';
        if (debug_flag && pre_b != -1) cout << "ans[" << tmp_b << "]에 "<< ten - 1 - pre_b << "이 빼져서" << ans[tmp_b] << "이 되었습니다. " << '\n';
        
        ten *= 10ll;
        pre_b = origin_b % ten;

        if (debug_flag) {
            cout << "ten은 10으로 곱해져서 " << ten << "이 되었습니다." << '\n';
            cout << "3. ans 상태" << '\n';
            for (int i = 0; i < 10; i++)
                cout << ans[i] << " ";
            cout << '\n' << '\n' << "---------------------종료-------------------" << '\n' << '\n';
        }

        if (debug_flag_just_ans) {
            cout << debug_cnt << "번째 ans 입니다. " << '\n';
            for (int i = 0; i < 10; i++)
                cout << ans[i] << " ";
            cout << '\n' << '\n';
        }
    }

    if (debug_flag_just_ans) cout << "마지막 ans 입니다. " << '\n';
    for (int i = 0; i < 10; i++)
        cout << ans[i] << " ";

    return 0;
}
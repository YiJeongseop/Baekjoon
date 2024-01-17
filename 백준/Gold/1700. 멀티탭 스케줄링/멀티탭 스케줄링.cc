#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

int N, K, ans = 0;
int order[101];
int socket[101];
bool check[101];
vector<int> pos[101];

//void debug_print(int i) {
//    cout << "현재 i는 " << i << "이며, 콘센트 상태는 이렇습니다. " << '\n';
//    for (int j = 1; j <= N; j++) {
//        cout << socket[j] << " ";
//    }
//    cout << '\n';
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> order[i];
        pos[order[i]].push_back(i);
    }
    if (N >= K) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        pos[order[i]].erase(pos[order[i]].begin());
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (check[order[j]]) continue;
            socket[i] = order[j];
            check[order[j]] = true;
            break;
        }
    }
    for (int i = N + 1; i <= K; i++) {
        bool flag = false;
        for (int j = 1; j <= N; j++) {
            if (order[i] == socket[j]) {
                flag = true;
                pos[socket[j]].erase(pos[socket[j]].begin());
                //debug_print(i);
                break;
            }
        }
        if (flag) continue;
        for (int j = 1; j <= N; j++) {
            if (pos[socket[j]].size() == 0) {
                flag = true;
                ans++;
                socket[j] = order[i];
                pos[socket[j]].erase(pos[socket[j]].begin());
                //debug_print(i);
                break;
            }
        }
        if (flag) continue;
        int max_idx = 0, idx = 0;
        for (int j = 1; j <= N; j++) {
            if (pos[socket[j]][0] > max_idx) {
                max_idx = pos[socket[j]][0];
                idx = j;
            }
        }
        ans++;
        socket[idx] = order[i];
        pos[socket[idx]].erase(pos[socket[idx]].begin());
        //debug_print(i);
    }
    cout << ans;
        
    return 0;
}
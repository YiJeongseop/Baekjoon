#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, ans = INT_MAX;
int mask[11];
int check[11];
int citizen[11];
vector<int> relation[11];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> citizen[i];

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            relation[i].push_back(b);
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        fill(mask + 1, mask + N + 1, 0);
        for (int j = N; j > N - i; j--) {
            mask[j] = 1;
        }
        do {

            //cout << "mask" << '\n';
            //for (int j = 1; j <= N; j++) {
            //    cout << mask[j] << " ";
            //}
            //cout << '\n';

            vector<int> a, b;
            for (int j = 1; j <= N; j++) {
                if (mask[j]) a.push_back(j);
                else b.push_back(j);
            }

            fill(check + 1, check + N + 1, 0);
            for (int j = 0; j < 1; j++) {
                if (check[a[j]]) continue;
                queue<int> q;
                q.push(a[j]);
                check[a[j]] = true;
                //cout << a[j] << "가 방문처리 되었습니다. " << '\n';
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int k = 0; k < relation[cur].size(); k++) {
                        if (check[relation[cur][k]] || !mask[relation[cur][k]]) continue;
                        check[relation[cur][k]] = true;
                        //cout << relation[cur][k] << "가 방문처리 되었습니다. " << '\n';
                        q.push(relation[cur][k]);
                    }
                }
            }
            //cout << "벡터 a 끝 " << '\n';

            bool flag = false;
            for (int j = 1; j <= N; j++) {
                if (mask[j] == 1 && !check[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            fill(check + 1, check + N + 1, 0);
            for (int j = 0; j < 1; j++) {
                if (check[b[j]]) continue;
                queue<int> q;
                q.push(b[j]);
                check[b[j]] = true;
                //cout << b[j] << "가 방문처리 되었습니다. " << '\n';
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int k = 0; k < relation[cur].size(); k++) {
                        if (check[relation[cur][k]] || mask[relation[cur][k]]) continue;
                        check[relation[cur][k]] = true;
                        //cout << relation[cur][k] << "가 방문처리 되었습니다. " << '\n';
                        q.push(relation[cur][k]);
                    }
                }
            }
            //cout << "벡터 b 끝 " << '\n';

            for (int j = 1; j <= N; j++) {
                if (mask[j] == 0 && !check[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            int aa = 0, bb = 0;
            for (int j = 1; j <= N; j++) {
                if (mask[j]) {
                    aa += citizen[j];
                }
                else {
                    bb += citizen[j];
                }
            }
            ans = min(ans, abs(aa - bb));
        } while (next_permutation(mask + 1, mask + N + 1));
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}
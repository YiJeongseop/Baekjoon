#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

int lc[10001], rc[10001], col[10001], row[10001], root_check[10001];
vector<int> v[10001];
int root, ro_cnt = 1, co_cnt = 1;

void inorder(int cur, int co) {
    row[cur] = co;
    if (lc[cur] == -1 && rc[cur] == -1) {
        col[cur] = co_cnt++;
        return;
    }
    if (lc[cur] != -1) inorder(lc[cur], co + 1);
    col[cur] = co_cnt++;
    if (rc[cur] != -1) inorder(rc[cur], co + 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b; rc[a] = c;
        if(b != -1) root_check[b] = 1; 
        if(c != -1) root_check[c] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!root_check[i]) {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    for (int i = 1; i <= N; i++) {
        v[row[i]].push_back(col[i]);
    }

    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= N; i++) {
        if (v[i].size() == 0) break;
        sort(v[i].begin(), v[i].end());

        if (v[i][v[i].size() - 1] - v[i][0] > ans2) {
            ans2 = v[i][v[i].size() - 1] - v[i][0];
            ans1 = i;
        }
    }

    cout << ans1 << " " << ans2 + 1;

    return 0;
}
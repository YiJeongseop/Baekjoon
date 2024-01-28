#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> adj[20001];
int vis[20001];
int ans[20001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans_val = 0;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    vis[1] = true;
    while (!q.empty()) {
        auto cur = q.front();
        ans[cur.first] = cur.second;
        ans_val = max(ans_val, cur.second);
        q.pop();
        for (int nxt : adj[cur.first]) {
            if (vis[nxt]) continue;
            q.push({ nxt, cur.second + 1 });
            vis[nxt] = true;
        }
    }

    int cnt = 0, idx = 0;
    for (int i = 1; i <= N; i++) {
        if (ans[i] == ans_val) {
            idx = i;
            cnt++;
            cout << i << " " << ans_val << " ";
            break;
        }
    }
    for (int i = idx + 1; i <= N; i++)
        if (ans[i] == ans_val) cnt++;

    cout << cnt;

    return 0;
}
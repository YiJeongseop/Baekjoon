#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> adj[51];
int vis[51];
int ans[51];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans2 = INT_MAX;
    for (int i = 1; i <= N; i++) {
        fill(vis, vis + N + 1, false);
        int score = 0;
        queue<pair<int, int>> q;
        q.push({i, 0});
        vis[i] = true;
        while (!q.empty()) {
            auto cur = q.front();
            score = max(score, cur.second);
            q.pop();
            for (int nxt : adj[cur.first]) {
                if (vis[nxt]) continue;
                q.push({ nxt, cur.second + 1 });
                vis[nxt] = true;
            }
        }
        ans[i] = score;
        ans2 = min(ans2, score);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (ans[i] == ans2) cnt++;
    }
    cout << ans2 << " " << cnt << '\n';
    for (int i = 1; i <= N; i++) {
        if (ans[i] == ans2) cout << i << " ";
    }

    return 0;
}
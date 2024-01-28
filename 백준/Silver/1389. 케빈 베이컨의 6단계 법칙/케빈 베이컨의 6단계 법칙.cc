#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> adj[101];
int vis[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans_idx = 1, ans_val = INT_MAX;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
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
            score += cur.second;
            q.pop();
            for (int nxt : adj[cur.first]) {
                if (vis[nxt]) continue;
                q.push({ nxt, cur.second + 1 });
                vis[nxt] = true;
            }
        }
        if (ans_val > score) {
            ans_val = score;
            ans_idx = i;
        }
    }

    cout << ans_idx;

    return 0;
}
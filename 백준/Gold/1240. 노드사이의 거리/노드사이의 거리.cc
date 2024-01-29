#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

vector<int> adj[1001];
int dis[1001][1001];
bool vis[1001];
int st, en;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dis[u][v] = val;
        dis[v][u] = val;
    }

    while (M--) {
        cin >> st >> en;
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({st, 0});
        vis[st] = true;
        while (!q.empty()) {
            auto cur = q.front();
            if (cur.first == en) {
                ans = cur.second;
            }
            q.pop();
            for (int nxt : adj[cur.first]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push({ nxt, cur.second + dis[cur.first][nxt] });
            }
        }
        cout << ans << '\n';
        fill(vis, vis + N + 1, false);
    }

    return 0;
}
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
int check[20001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K; cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;
        for (int i = 1; i <= V; i++) adj[i].clear();
        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(vis, vis + V + 1, false);
        fill(check, check + V + 1, -1);
        bool no = false;

        for (int i = 1; i <= V; i++) {
            if (vis[i]) continue;
            queue<pair<int, int>> q;
            q.push({ i, 0 });
            vis[i] = true;
            check[i] = 0;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (auto nxt : adj[cur.first]) {
                    if (vis[nxt]) {
                        if (check[nxt] == cur.second) {
                            no = true;
                            break;
                        }
                        continue;
                    }
                    q.push({ nxt, (cur.second == 0) ? 1 : 0 });
                    vis[nxt] = true;
                    check[nxt] = (cur.second == 0) ? 1 : 0;
                }
                if (no) break;
            }
            if (no) break;
        }
        if (no) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}
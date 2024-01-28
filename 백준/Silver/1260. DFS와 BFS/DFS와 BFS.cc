#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[1001];
int vis[1001];

void dfs(int cur) {
    vis[cur] = 1;
    cout << cur << " ";
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

    dfs(V);
    cout << '\n';

    fill(vis, vis + N + 1, 0);
    queue<int> q;
    q.push(V);
    cout << V << " ";
    vis[V] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            cout << nxt << " ";
            vis[nxt] = true;
        }
    }

    return 0;
}
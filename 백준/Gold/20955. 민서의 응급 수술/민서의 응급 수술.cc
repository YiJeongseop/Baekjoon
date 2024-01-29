#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

vector<int> adj[100001];
bool vis[100001];

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        cnt++;
        vis[i] = true;
        dfs(i);
    }

    cout << cnt - 1 + M + cnt - 1 - N + 1;

    return 0;
}
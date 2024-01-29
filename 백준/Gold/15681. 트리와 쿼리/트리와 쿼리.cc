#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int ans[100001];
vector<int> adj[100001];

int dfs(int cur, int p) {
    ans[cur] = 1;
    for (int nxt : adj[cur]) {
        if (p == nxt) continue;
        ans[cur] += dfs(nxt, cur);
    }
    return ans[cur];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R, -1);

    while (Q--) {
        int u;
        cin >> u;
        cout << ans[u] << '\n';
    }

    return 0;
}
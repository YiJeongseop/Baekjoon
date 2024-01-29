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
int ans[100001];
bool vis[100001];

void dfs(int cur, int par) {
    if(par != -1) ans[cur] += ans[par];
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, cur);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if (a == -1) continue;
        adj[a].push_back(i);
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        ans[a] += b;
    }

    for (int i = 1; i <= M; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i, -1);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";

    return 0;
}
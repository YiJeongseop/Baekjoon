#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> adj[10001];
int vis[10001];
int ans[10001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ans_val = 0;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        fill(vis, vis + N + 1, false);
        int score = 0;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            score++;
            q.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
        ans_val = max(ans_val, score);
        ans[i] = score;
    }

    for (int i = 1; i <= N; i++)
        if (ans[i] == ans_val) cout << i << " ";

    return 0;
}
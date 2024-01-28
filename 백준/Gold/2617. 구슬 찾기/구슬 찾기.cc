#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> adj[100];
vector<int> adj2[100];
int vis[100];
bool done[100];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    int standard = N / 2 + 1, ans = 0;
    for (int i = 1; i <= N; i++) {
        //cout << "i : " << i << '\n';
        fill(vis, vis + N + 1, false);
        queue<int> q;
        q.push(i);
        int cnt = 0;
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
                cnt++;
                //cout << "nxt : " << nxt << ", cnt : " << cnt << '\n';
            }
        }
        if (cnt >= standard) {
            done[i] = true;
            ans++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (done[i]) continue;
        //cout << "i : " << i << '\n';
        fill(vis, vis + N + 1, false);
        queue<int> q;
        q.push(i);
        int cnt = 0;
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : adj2[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
                cnt++;
                //cout << "nxt : " << nxt << ", cnt : " << cnt << '\n';
            }
        }
        if (cnt >= standard) {
            done[i] = true;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
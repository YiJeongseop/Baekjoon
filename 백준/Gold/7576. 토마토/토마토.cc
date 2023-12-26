#include <iostream>
#include <queue>

using namespace std;

int dist[1000][1000];
int m, n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dist[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] == -1) continue;
			if (dist[nx][ny] <= dist[cur.first][cur.second] + 1 && dist[nx][ny] != 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else if(dist[i][j] > max) {
				max = dist[i][j];
			}
		}
	}

	cout << max - 1;

	return 0;
}
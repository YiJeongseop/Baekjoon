#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0 };
int arr[1000][1000];
int arr2[1000][1000];
queue<pair<int, int>> q;
int T, w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	while (T--) {
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			fill(arr[i], arr[i] + w, 0);
			fill(arr2[i], arr2[i] + w, 0);
		}

		char c;
		int player_x, player_y;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> c;
				if (c == '#') {
					arr[y][x] = -1;
					arr2[y][x] = -1;
				}
				else if (c == '@') {
					arr2[y][x] = 1;
					player_x = x;
					player_y = y;
				}
				else if (c == '*') {
					arr[y][x] = 1;
					q.push({ y, x });
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (arr[ny][nx]) continue;
				if (arr[ny][nx] == -1) continue;
				arr[ny][nx] = arr[cur.first][cur.second] + 1;
				q.push({ ny, nx});
			}
		}

		bool flag = false;
		q.push({ player_y, player_x});
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					cout << arr2[cur.first][cur.second] << '\n';
					flag = true;
					break;
				}
				if (arr2[ny][nx] || (arr[ny][nx] > 0 && arr[ny][nx] <= arr2[cur.first][cur.second] + 1)) continue;
				if (arr2[ny][nx] == -1) continue;
				arr2[ny][nx] = arr2[cur.first][cur.second] + 1;
				q.push({ ny, nx});
			}
			if (flag) break;
		}
		if (flag) continue;
		else cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}
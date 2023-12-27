#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int arr[300][300];
queue<tuple<int, int, int>> q;
int T, l, start_x, start_y, end_x, end_y;

void bfs(int x, int y) {
	bool flag = false;
	arr[y][x] = 0;
	q.push({ x, y, 0 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if (arr[ny][nx] >= 0) continue;
			arr[ny][nx] = arr[get<1>(cur)][get<0>(cur)] + 1;
			if (ny == end_y && nx == end_x) {
				cout << arr[ny][nx] << '\n';
				flag = true;
				break;
			}
			q.push({ nx, ny, arr[ny][nx] });
		}
		if (flag) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	while (T--) {
		cin >> l >> start_x >> start_y >> end_x >> end_y;

		for (int i = 0; i < l; i++) {
			fill(arr[i], arr[i] + l, -1);
		}
		
		while (!q.empty()) {
			q.pop();
		}

		if (start_x == end_x && start_y == end_y) {
			cout << 0 << '\n';
			continue;
		}
		bfs(start_x, start_y);
	}

	return 0;
}
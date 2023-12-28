#include <iostream>
#include <queue>

using namespace std;

int arr[100][100];
bool visit[100][100];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int N, min_ = 101, max_ = 0, count_, max_value = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] > max_) max_ = arr[y][x];
			if (arr[y][x] < min_) min_ = arr[y][x];
		}
	}

	queue<pair<int, int>> q;

	for (int i = min_; i < max_; i++) {
		for (int j = 0; j < N; j++) {
			fill(visit[j], visit[j] + N, false);
		}
		count_ = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (arr[y][x] > i && !visit[y][x]) {
					count_++;
					q.push({y, x});
					visit[y][x] = true;
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.second + dx[dir];
							int ny = cur.first + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							if (visit[ny][nx] || arr[ny][nx] <= i) continue;
							visit[ny][nx] = true;
							q.push({ ny, nx });
						}
					}
					if (count_ > max_value) max_value = count_;
				}
			}
		}
	}

	cout << max_value;

	return 0;
}
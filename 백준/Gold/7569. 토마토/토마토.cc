#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int arr[100][100][100];
// bool check[100][100][100];
queue<tuple<int, int, int>> q;
int M, N, H;

void bfs(int x, int y, int z) {
	q.push({z, y, x});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<2>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
			if (arr[nz][ny][nx] == 1 || arr[nz][ny][nx] == -1) continue;
			if (arr[nz][ny][nx] != 0 && arr[nz][ny][nx] <= arr[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1) continue;
			arr[nz][ny][nx] = arr[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			// cout << "z 좌표 : " << nz << ", y 좌표 : " << ny << ", x 좌표 : " << nx << "의 토마토는 값이 " << arr[nz][ny][nx] << "가 되었습니다!" << '\n';
			q.push({ nz, ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> M >> N >> H;

	bool all_done = true;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0) all_done = false;
			}
		}
	}

	if (all_done) {
		cout << 0;
		return 0;
	}

	//for (int i = 0; i < H; i++) {
	//	for (int j = 0; j < N; j++) {
	//		fill(check[i][j], check[i][j] + M, false);
	//	}
	//}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 1) bfs(k, j, i);
			}
		}
	}

	int max = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else if (max < arr[i][j][k]) {
					max = arr[i][j][k];
				}
			}
		}
	}

	cout << max - 1;

	return 0;
}
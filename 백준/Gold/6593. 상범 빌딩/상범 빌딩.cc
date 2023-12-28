#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[30][30][30];
int dx[6] = { 0, -1, 0, 1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int L, R, C, start_z, start_y, start_x;
char temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> L >> R >> C;

	while (L != 0 && R != 0 && C != 0) {
		for (int z = 0; z < L; z++) {
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					cin >> temp;
					if (temp == 'S') {
						arr[z][y][x] = 1;
						start_x = x; start_y = y; start_z = z;
					}
					else if (temp == '.') {
						arr[z][y][x] = 0;
					}
					else if (temp == 'E') {
						arr[z][y][x] = -1;
					}
					else if (temp == '#') {
						arr[z][y][x] = -2;
					}
				}
			}
		}

		queue<tuple<int, int, int>> q;
		q.push({ start_z, start_y, start_x });

		bool flag = false;
		int answer;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nz = get<0>(cur) + dz[dir];
				int ny = get<1>(cur) + dy[dir];
				int nx = get<2>(cur) + dx[dir];
				if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
				if (arr[nz][ny][nx] == -2 || arr[nz][ny][nx] >= 1) continue;
				if (arr[nz][ny][nx] == -1) {
					flag = true;
					answer = arr[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					break;
				}
				arr[nz][ny][nx] += arr[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push({ nz, ny, nx });
			}
			if (flag) break;
		}
		if (flag) {
			cout << "Escaped in " << answer - 1 << " minute(s)." << '\n';
		}
		else {
			cout << "Trapped!" << '\n';
		}

		cin >> L >> R >> C;
	}

	return 0;
}
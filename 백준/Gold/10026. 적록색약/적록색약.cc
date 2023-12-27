#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define X first
#define Y second

int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
string arr[100];
bool check[100][100];
bool check2[100][100];
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
char c;
int count1 = 0, count2 = 0;

void bfs(int x, int y) {
	count1++;
	c = arr[y][x];
	check[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (check[nx][ny] || arr[ny][nx] != c) continue;
			check[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

void bfs2(int x, int y) {
	count2++;
	c = arr[y][x];
	check2[x][y] = true;
	q2.push({ x, y });
	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (check2[nx][ny] || ((c == 'R' || c == 'G') && arr[ny][nx] == 'B')) continue;
			if (check2[nx][ny] || (c == 'B' && arr[ny][nx] != 'B')) continue;
			check2[nx][ny] = true;
			q2.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		fill(check[i], check[i] + N, false);
		fill(check2[i], check2[i] + N, false);
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!check[x][y]) {
				bfs(x, y);
			}
			if (!check2[x][y]) {
				bfs2(x, y);
			}
		}
	}

	cout << count1 << " " << count2;

	return 0;
}
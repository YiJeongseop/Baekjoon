#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

string arr[25];
bool visit[25][25];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int y = 0; y < N; y++) {
		cin >> arr[y];
	}

	int count1 = 0, count2;
	queue<pair<int, int>> q;
	vector<int> v;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == '1' && !visit[y][x]) {
				count2 = 0;
				count1++;
				count2++;
				q.push({ y, x });
				visit[y][x] = true;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for(int dir = 0; dir < 4; dir++) {
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (visit[ny][nx] || arr[ny][nx] == '0') continue;
						visit[ny][nx] = true;
						count2++;
						q.push({ ny, nx });
					}
					if (q.empty()) v.push_back(count2);
				}
			}
		}
	}

	cout << count1 << '\n';

	sort(v.begin(), v.end());

	for (int i = 0; i < count1; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
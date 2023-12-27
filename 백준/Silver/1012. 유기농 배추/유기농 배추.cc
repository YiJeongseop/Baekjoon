#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool check[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	while (T--) {
		int m, n, k;
		cin >> m >> n >> k;
		int** arr = new int*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			fill(arr[i], arr[i] + m, 0);
		}
		for (int i = 0; i < n; i++) {
			fill(check[i], check[i] + m, false);
		}

		queue<pair<int, int>> q;
		stack<pair<int, int>> s;

		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
			s.push({ x, y });
		}

		auto item = s.top();
		s.pop();
		q.push(item);
		check[item.second][item.first] = true;

		int count = 0;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (arr[cur.second][cur.first] == 2) {
				if (q.empty() && !s.empty()) {
					auto item = s.top();
					s.pop();
					check[item.second][item.first] = true;
					q.push(item);
				}
				continue;
			}
			arr[cur.second][cur.first] = 2;

			for (int d = 0; d < 4; d++) {
				int temp_x = cur.first + dx[d];
				int temp_y = cur.second + dy[d];
				if (temp_x > m - 1 || temp_x < 0 || temp_y > n - 1 || temp_y < 0) continue;
				if (check[temp_y][temp_x]) continue;
				if (arr[temp_y][temp_x] == 1) {
					check[temp_y][temp_x] = true;
					q.push({ temp_x, temp_y });
				}
			}

			if (q.empty()) {
				count++;
				if (!s.empty()) {
					auto item = s.top();
					s.pop();
					check[item.second][item.first] = true;
					q.push(item);
				}
			}
		}
		cout << count << '\n';

		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	return 0;
}
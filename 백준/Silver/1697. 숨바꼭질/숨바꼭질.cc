#include <iostream>
#include <queue>

using namespace std;

int arr[200001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({N, 0});
	arr[N] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.first == K) {
			cout << cur.second;
			return 0;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0 && cur.first + 1 <= 200000) {
				if (arr[cur.first + 1] != 0) continue;
				q.push({ cur.first + 1, cur.second + 1 });
				arr[cur.first + 1] = cur.second + 1;
			}
			else if (i == 1 && cur.first - 1 >= 0) {
				if (arr[cur.first - 1] != 0) continue;
				q.push({ cur.first - 1, cur.second + 1 });
				arr[cur.first - 1] = cur.second + 1;
			}
			else if (i == 2 && cur.first * 2 <= 200000) {
				if (arr[cur.first * 2] != 0) continue;
				q.push({ cur.first * 2, cur.second + 1 });
				arr[cur.first * 2] = cur.second + 1;
			}
		}
	}

	return 0;
}
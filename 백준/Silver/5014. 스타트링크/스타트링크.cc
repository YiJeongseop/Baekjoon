#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];
//bool visit[25][25];
//int dx[4] = { 0, -1, 0, 1 };
//int dy[4] = { 1, 0, -1, 0 };
int F, S, G, U, D;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> F >> S >> G >> U >> D;

	queue<int> q;

	fill(arr, arr + F + 1, -1);

	q.push(S);
	arr[S] = 0;

	bool flag = false;
	while (!q.empty()) {
		int cur = q.front();
		//cout << "현재 cur 값은 " << cur << "입니다." << '\n';
		if (cur == G) {
			flag = true;
			break;
		}
		q.pop();
		if (cur - D < 1 && cur + U > F) continue;
		else if (cur + U > F) {
			if (arr[cur - D] != -1 && arr[cur - D] <= arr[cur]) continue;
			arr[cur - D] = arr[cur] + 1;
			//cout << cur - D << " 를 Q에 PUSH합니다." << '\n';
			q.push(cur - D);
		}
		else if (cur - D < 1) {
			if (arr[cur + U] != -1 && arr[cur + U] <= arr[cur]) continue;
			arr[cur + U] = arr[cur] + 1;
			//cout << cur + U << " 를 Q에 PUSH합니다." << '\n';
			q.push(cur + U);
		}
		else {
			if (arr[cur - D] == -1) {
				arr[cur - D ] = arr[cur] + 1;
				//cout << cur - D << " 를 Q에 PUSH합니다." << '\n';
				q.push(cur - D);
			}
			if (arr[cur + U] == -1) {
				arr[cur + U] = arr[cur] + 1;
				//cout << cur + U << " 를 Q에 PUSH합니다." << '\n';
				q.push(cur + U);
			}
		}
	}

	//for (int i = 0; i < 10; i++) {
	//	cout << arr[i] << " ";
	//}
	//cout << '\n';

	if (flag)cout << arr[G];
	else cout << "use the stairs";

	return 0;
}
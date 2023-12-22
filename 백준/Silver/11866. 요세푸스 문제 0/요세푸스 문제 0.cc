#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int n, k, temp, order = 0;
	cin >> n >> k;

	int* arr = new int[n];

	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		temp = q.front();
		q.pop();
		arr[order++] = temp;
	}

	if (n != 1) {
		cout << "<" << arr[0] << ",";
		for (int i = 1; i < n; i++) {
			cout << " " << arr[i];
			if (i != n - 1) {
				cout << ",";
			}
		}
		cout << ">";
	}
	else {
		cout << "<" << arr[0] << ">";
	}

	delete[] arr;

	return 0;
}
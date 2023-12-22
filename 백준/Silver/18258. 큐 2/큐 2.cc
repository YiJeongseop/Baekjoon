#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int n, value;
	cin >> n;

	string command;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			cin >> value;
			q.push(value);
		}
		else if (command == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << '\n';
		}
		else if (command == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (command == "back") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}

	return 0;
}
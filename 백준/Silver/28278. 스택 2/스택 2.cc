#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, command, push_value;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == 1) {
			cin >> push_value;
			s.push(push_value);
		}
		else if (command == 2) {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (command == 3) {
			cout << s.size() << '\n';
		}
		else if (command == 4) {
			if (s.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == 5) {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
	}

	return 0;
}
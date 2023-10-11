#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	using namespace std;

	queue<int> q;

	int n, num;
	string cmd;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd.substr(0, 4) == "push") {
			int num;
			cin >> num;
			q.push(num);
		}

		else if (cmd == "pop") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}

		else if (cmd == "size") {
			cout << q.size() << endl;
		}

		else if (cmd == "empty") {
			if (q.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}

		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}

		else if (cmd == "back") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}
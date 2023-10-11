#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	using namespace std;

	deque<int> q;

	int n, num;
	string cmd;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd.substr(0, 10) == "push_front") {
			int num;
			cin >> num;
			q.push_front(num);
		}

		else if (cmd.substr(0, 9) == "push_back") {
			int num;
			cin >> num;
			q.push_back(num);
		}

		else if (cmd == "pop_front") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}

		else if (cmd == "pop_back") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.back() << endl;
				q.pop_back();
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
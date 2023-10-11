#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	using namespace std;

	stack<int> s;

	int n, num;
	string cmd;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd.substr(0, 4) == "push") {
			int num;
			cin >> num;
			s.push(num);
		}

		else if (cmd == "pop") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}

		else if (cmd == "size") {
			cout << s.size() << endl;
		}

		else if (cmd == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}

		else if (cmd == "top") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
	}

	return 0;
}
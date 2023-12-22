#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, command, value;
	cin >> n;
	deque<int> d;

	for (int i = 0; i < n; i++) {
		cin >> command;
		switch (command) 
		{
			case 1:
				cin >> value;
				d.push_front(value);
				break;
			case 2:
				cin >> value;
				d.push_back(value);
				break;
			case 3:
				if (d.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << d.front() << '\n';
					d.pop_front();
				}
				break;
			case 4:
				if (d.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << d.back() << '\n';
					d.pop_back();
				}
				break;
			case 5:
				cout << d.size() << '\n';
				break;
			case 6:
				if (d.empty()) {
					cout << 1 << '\n';
				}
				else {
					cout << 0 << '\n';
				}
				break;
			case 7:
				if (d.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << d.front() << '\n';
				}
				break;
			case 8:
				if (d.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << d.back() << '\n';
				}
				break;
		}
	}

	return 0;
}
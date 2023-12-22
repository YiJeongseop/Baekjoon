#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	getline(cin, str, '.');

	stack<char> s;
	bool flag = false;

	while (str.length() != 1) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				s.push('(');
			}
			else if (str[i] == ')') {
				if (s.empty() || s.top() == '[') {
					flag = true;
					break;
				}
				else {
					s.pop();
				}
			}
			else if (str[i] == '[') {
				s.push('[');
			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() == '(') {
					flag = true;
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (flag) {
			cout << "no" << '\n';
		}
		else {
			if (!s.empty()) {
				cout << "no" << '\n';
			}
			else {
				cout << "yes" << '\n';
			}
		}

		while (!s.empty()) s.pop();

		getline(cin, str, '.');
		flag = false;
	}

	return 0;
}
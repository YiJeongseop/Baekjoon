#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	stack<char> s;
	string st;

	for (int i = 0; i < t; i++) {
		cin >> st;
		bool flag = false;

		for (int j = 0; j < st.length(); j++) {
			if (st[j] == '(') {
				s.push('(');
			}
			else {
				if (!s.empty()) {
					s.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}

		if (flag == true) cout << "NO" << '\n';
		else if (!s.empty()) cout << "NO" << '\n';
		else cout << "YES" << '\n';

		while (!s.empty()) s.pop();
	}

	return 0;
}

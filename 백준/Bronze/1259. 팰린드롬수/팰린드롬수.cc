#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;

	cin >> n;
	while (n != 0) {
		str = to_string(n);

		if (str.length() == 1) {
			cout << "yes" << '\n';
		}
		else {
			for (int i = 0; i < str.length() / 2; i++) {
				if (str[i] != str[str.length() - 1 - i]) {
					cout << "no" << '\n';
					break;
				}
				else if (i == str.length() / 2 - 1) {
					cout << "yes" << '\n';
				}
			}
		}

		cin >> n;
	}

	return 0;
}
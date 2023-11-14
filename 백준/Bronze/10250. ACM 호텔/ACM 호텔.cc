#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, h, w, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;

		if (n % h == 0) {
			if (to_string(n / h).length() == 1) {
				cout << to_string(h) << "0" << to_string(n / h) << '\n';
			}
			else {
				cout << to_string(h) << to_string(n / h) << '\n';
			}
		}
		else {
			if (to_string(n / h + 1).length() == 1) {
				cout << to_string(n % h) << "0" << to_string(n / h + 1) << '\n';
			}
			else {
				cout << to_string(n % h) << to_string(n / h + 1) << '\n';
			}
		}
	}

	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	// a1 * n + a0 <= c * n    (c - a1)n >= a0

	if (c == a1) {
		if (a0 <= 0) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if (c > a1) {
		if (((c - a1) * n0) >= a0) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		cout << 0;
	}

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, up = 1, down = 1;
	cin >> n >> k;

	for (int i = n; i > 0; i--) {
		up *= i;
	}

	for (int i = k; i > 0; i--) {
		down *= i;
	}

	for (int i = n - k; i > 0; i--) {
		down *= i;
	}

	cout << up / down;

	return 0;
}
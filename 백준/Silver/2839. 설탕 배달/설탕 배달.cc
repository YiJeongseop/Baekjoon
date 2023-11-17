#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 3) {
		cout << 1;
	}
	else if (n == 4) {
		cout << -1;
	}
	else {
		int min = 5000;
		for (int i = 0; i < (n / 5) + 1; i++) {
			for (int j = 0; j < (n / 3) + 1; j++) {
				if (5 * i + 3 * j == n) {
					if (i + j < min) {
						min = i + j;
					}
				}
			}
		}
		if (min == 5000) {
			cout << -1;
		}
		else {
			cout << min;
		}
	}

	return 0;
}
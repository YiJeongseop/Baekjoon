#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k, count = 0;

	cin >> n >> k;

	// 제곱근이 정수일 때
	if (sqrt(n) - (int)sqrt(n) == 0) {
		for (int i = 1; i < sqrt(n); i++) {
			if (n % i == 0) {
				count++;
				if (k == count) {
					cout << i;
					return 0;
				}
			}
		}
		count++;
		if (k == count) {
			cout << sqrt(n);
			return 0;
		}
		for (int i = (int)sqrt(n) - 1; i > 0; i--) {
			if (n % i == 0) {
				count++;
				if (k == count) {
					cout << n / i;
					return 0;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= (int)sqrt(n); i++) {
			if (n % i == 0) {
				count++;
				if (k == count) {
					cout << i;
					return 0;
				}
			}
		}
		for (int i = (int)sqrt(n); i > 0; i--) {
			if (n % i == 0) {
				count++;
				if (k == count) {
					cout << n / i;
					return 0;
				}
			}
		}
	}

	cout << 0;

	return 0;
}
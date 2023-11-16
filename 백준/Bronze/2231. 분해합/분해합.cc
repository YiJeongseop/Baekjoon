#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = 0;
		int temp = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (i + sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;

	return 0;
}
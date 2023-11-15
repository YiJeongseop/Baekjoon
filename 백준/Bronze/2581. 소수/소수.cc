#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int m, n, sum = 0, min = -1;
	bool flag = true;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (i == 1) {
			continue;
		}
		else if (i == 2 || i == 3) {
			sum += i;
			if (min != 2) {
				min = i;
				flag = false;
			}
		}
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				break;
			}
			else if (j == (int)sqrt(i)) {
				sum += i;
				if (flag) {
					min = i;
					flag = false;
				}
			}
		}
	}

	if (sum == 0 && min == -1) {
		cout << -1;
	}
	else {
		cout << sum << endl << min;
	}

	return 0;
}
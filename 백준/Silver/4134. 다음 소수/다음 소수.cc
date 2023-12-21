#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		bool flag = true;
		cin >> n;
		if (n == 0) {
			cout << 2 << '\n';
			continue;
		}
		else if (n == 1) {
			cout << 2 << '\n';
			continue;
		}
		while (flag) {
			flag = false;
			for (long long j = 2; j <= sqrt(n); j++) {
				if (n % j == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << n << '\n';
				break;
			}
			n++;
		}
	}

	return 0;
}
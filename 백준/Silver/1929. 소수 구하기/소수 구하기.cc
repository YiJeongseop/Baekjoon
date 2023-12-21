#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = m; i < n + 1; i++) {
		if (i == 1) {
			continue;
		}
		else if (i == 2) {
			cout << 2 << '\n';
			continue;
		}
		else if (i == 3) {
			cout << 3 << '\n';
			continue;
		}
		else {
			bool flag = false;
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) cout << i << '\n';
		}
	}

	return 0;
}
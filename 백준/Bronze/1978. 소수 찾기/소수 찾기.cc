#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, value, count = 0;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> value;
		if (value >= 2 && value <= 3) {
			count++;
			continue;
		}
		for (int j = 2; j <= (int)sqrt(value); j++) {
			if (value % j == 0) {
				break;
			}
			else if (j == (int)sqrt(value)) {
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
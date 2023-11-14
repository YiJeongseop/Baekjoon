#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	int cur = 2;
	int i = 1;
	while (true) {
		if (n >= cur && n < cur + 6 * i) {
			cout << i + 1;
			return 0;
		}
		cur += 6 * i;
		i++;
	}

	return 0;
}
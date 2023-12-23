#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d, e, f, g, sum = 0, min = 100;
	cin >> a;
	if (a % 2 == 1) {
		sum += a;
		if (min > a) {
			min = a;
		}
	}

	cin >> b;
	if (b % 2 == 1) {
		sum += b;
		if (min > b) {
			min = b;
		}
	}

	cin >> c;
	if (c % 2 == 1) {
		sum += c;
		if (min > c) {
			min = c;
		}
	}

	cin >> d;
	if (d % 2 == 1) {
		sum += d;
		if (min > d) {
			min = d;
		}
	}

	cin >> e;
	if (e % 2 == 1) {
		sum += e;
		if (min > e) {
			min = e;
		}
	}

	cin >> f;
	if (f % 2 == 1) {
		sum += f;
		if (min > f) {
			min = f;
		}
	}

	cin >> g;
	if (g % 2 == 1) {
		sum += g;
		if (min > g) {
			min = g;
		}
	}

	if (sum == 0) {
		cout << -1;
		return 0;
	}

	cout << sum << '\n' << min;

	return 0;
}
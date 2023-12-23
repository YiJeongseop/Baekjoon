#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int gcd_value;

void gcd(int a, int b) {
	if (b == 0) {
		gcd_value = a;
	}
	else {
		gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	gcd(a, b);

	cout << gcd_value << '\n' << a * b / gcd_value;

	return 0;
}
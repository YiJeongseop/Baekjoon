#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, quotient, remainder, b = 0;
	string result = "";

	cin >> n >> b;
	quotient = n;

	while (true) {
		remainder = quotient % b;
		quotient = quotient / b;

		if (remainder >= 0 && remainder <= 9) {
			result = to_string(remainder) + result;
		}
		else {
			result = (char)(remainder + 55) + result;
		}

		if (quotient == 0) {
			break;
		}
	}

	cout << result;

	return 0;
}
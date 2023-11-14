#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int first, second;

	cin >> first >> second;
	while (first != 0 || second != 0) {
		if (second % first == 0) {
			cout << "factor" << '\n';
		}
		else if (first % second == 0) {
			cout << "multiple" << '\n';
		}
		else {
			cout << "neither" << '\n';
		}

		cin >> first >> second;
	}

	return 0;
}
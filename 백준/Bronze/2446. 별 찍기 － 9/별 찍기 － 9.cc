#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i < 2 * n; i++) {
		for (int j = 0; j < abs(n - 1 -abs(n - i)); j++) {
			cout << " ";
		}
		for (int j = 0; j < abs(n - i); j++) {
			cout << "*";
		}
		cout << "*";
		for (int j = 0; j < abs(n - i); j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}
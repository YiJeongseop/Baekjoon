#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < n * 2 - (i * 2 - 1); j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}
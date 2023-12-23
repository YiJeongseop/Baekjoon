#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int arr2[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int a, b;

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			arr2[b + a - i - 1] = arr[i - 1];
		}
		for (int i = 0; i < 20; i++) {
			arr[i] = arr2[i];
		}
	}

	for (int i = 0; i < 20; i++) {
		if (arr2[i] == -1) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr2[i] << " ";
		}
	}

	return 0;
}
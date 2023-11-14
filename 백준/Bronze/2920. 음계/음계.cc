#include <iostream>

using namespace std;

int main() {
	int arr[8];

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int count = 0;
	for (int i = 1; i < 8; i++) {
		if (arr[i] > arr[i - 1]) {
			count++;
		}
		else {
			count--;
		}
	}
	
	if (count == 7) {
		cout << "ascending";
	}
	else if (count == -7) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}

	return 0;
}
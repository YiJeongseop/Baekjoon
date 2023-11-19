#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;

	int* arr2 = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < m; i++) {
		if (binary_search(arr, arr + n, arr2[i])) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

	delete[] arr, arr2;

	return 0;
}

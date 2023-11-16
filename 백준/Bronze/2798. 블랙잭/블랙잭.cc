#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, m, temp;
	cin >> n >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > max) {
					max = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}

	cout << max;

	delete[] arr;

	return 0;
}
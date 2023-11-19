#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	map<int, int> m;
	cin >> n;
		
	int* arr = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}

	sort(arr, arr + n);

	int j = 0;
	for (int i = 0; i < n; i++) {
		m.insert({arr[i], j});
		if (arr[i] < arr[i + 1] && i != n - 1) {
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << m.at(arr2[i]) << " ";
	}

	delete[] arr;
	delete[] arr2;

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	string n_str = to_string(n);
	int* arr = new int[n_str.length()];

	for (int i = 0; i < n_str.length(); i++) {
		arr[i] = n_str[i] - '0';
	}

	sort(arr, arr + n_str.length(), greater<int>());

	for (int i = 0; i < n_str.length(); i++) {
		cout << arr[i];
	}

	delete[] arr;

	return 0;
}
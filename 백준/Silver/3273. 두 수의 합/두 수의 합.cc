#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, temp2, count = 0;
	vector<int> v;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> x;
	for (int i = 0; i < n; i++) {
		if (arr[i] < x && i != 0) {
			temp2 = x - arr[i];
			if (find(v.begin(), v.end(), temp2) != v.end()) {
				count++;
			}
		}
		v.push_back(arr[i]);
	}

	cout << count;

	delete[] arr;

	return 0;
}
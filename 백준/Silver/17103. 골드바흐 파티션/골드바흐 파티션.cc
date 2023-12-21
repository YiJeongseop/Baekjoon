#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	bool* arr = new bool[1000000];
	for (int i = 0; i < 1000000; i++) {
		arr[i] = true;
	}

	arr[0] = false;

	for (int i = 2; i * i < 1000001; i++) {
		if (arr[i - 1]) {
			for (int j = 2; i * j < 1000001; j++) {
				arr[i * j - 1] = false;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		int count = 0;
		cin >> n;
		for (int j = 2; j <= n / 2; j++) {
			if (arr[j - 1] && arr[n - j - 1]) {
				count++;
			}
		}
		cout << count << '\n';
	}
	delete[] arr;

	return 0;
}

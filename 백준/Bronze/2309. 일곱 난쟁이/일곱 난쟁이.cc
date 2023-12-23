#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9];
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) {
				continue;
			}
			else {
				int sum = 0;
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					else {
						sum += arr[k];
					}
				}
				if (sum == 100) {
					for (int k = 0; k < 9; k++) {
						if (k == i || k == j) {
							continue;
						}
						else {
							v.push_back(arr[k]);
						}
					}
					sort(v.begin(), v.end());
					for (int k = 0; k < 7; k++) {
						cout << v[k] << '\n';
					}
					return 0;
				}
			}
		}
	}

	return 0;
}
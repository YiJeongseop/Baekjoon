#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, a, b;
	cin >> n >> k;

	int arr[12] = {};
	int count = 0;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[a + b * 2 - 2]++;
	}

	for (int i = 0; i < 12; i++) {
		if (arr[i] == 0) continue;
		else if (arr[i] % k == 0) {
			count += arr[i] / k;
		}
		else {
			count += arr[i] / k + 1;
		}
	}

	cout << count;

	return 0;
}
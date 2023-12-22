#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int average = round(sum / (float)n);
	cout << average << '\n';

	sort(arr, arr + n);
	cout << arr[n / 2] << '\n';

	pair<int, int> arr2[8001];
	for (int i = 0; i < 8001; i++) {
		arr2[i] = make_pair(i - 4000, 0);
	}
	for (int i = 0; i < n; i++) {
		arr2[arr[i] + 4000].second += 1;
	}
	sort(arr2, arr2 + 8001, compare);
	if (arr2[0].second == arr2[1].second) {
		cout << arr2[1].first << '\n';
	}
	else {
		cout << arr2[0].first << '\n';
	}

	cout << arr[n - 1] - arr[0] << '\n';

	delete[] arr;

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;

	int arr[26] = {};
	int arr2[26] = {};

	string str1, str2;

	cin >> str1 >> str2;

	for (auto s : str1) {
		arr[s - 'a']++;
	}
	for (auto s : str2) {
		arr2[s - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] != arr2[i]) {
			count += abs(arr[i] - arr2[i]);
		}
	}

	cout << count;

	return 0;
}
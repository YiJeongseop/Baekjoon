#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[26] = {};
	int arr2[26] = {};

	string str1, str2;

	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;

		int arr[26] = {};
		int arr2[26] = {};

		for (auto s : str1) {
			arr[s - 'a']++;
		}
		for (auto s : str2) {
			arr2[s - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] != arr2[i]) {
				cout << "Impossible" << '\n';
				break;
			}
			else if (i == 25) {
				cout << "Possible" << '\n';
			}
		}
	}

	return 0;
}
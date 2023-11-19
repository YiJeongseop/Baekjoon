#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	map<string, bool> ma;
	string* arr = new string[n];
	string* arr2 = new string[m];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ma.insert({ arr[i], true });
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
		if (ma.find(arr2[i]) != ma.end()) {
			count++;
		}
	}

	cout << count;

	delete[] arr, arr2;

	return 0;
}

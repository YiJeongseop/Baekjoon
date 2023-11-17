#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp;
	cin >> n;

	int arr[10000] = { 0, };

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		for(int j = 0; j < arr[i]; j++){
			cout << i + 1 << '\n';
		}
	}

	return 0;
}
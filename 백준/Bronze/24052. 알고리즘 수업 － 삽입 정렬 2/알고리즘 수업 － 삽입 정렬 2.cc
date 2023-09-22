#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, temp;
	cin >> n >> k;

	int* array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> temp;
		array[i] = temp;
	}

	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int loc = i - 1;
		int newItem = array[i];
		for (; loc > -1 && array[loc] > newItem; loc--) {
			cnt++;
			if (cnt == k + 1) {
				for (int j = 0; j < n; j++) {
					cout << array[j] << " ";
				}
			}
			array[loc + 1] = array[loc];
		}
		if (loc != i - 1) {
			cnt++;
			if (cnt == k + 1) {
				for (int j = 0; j < n; j++) {
					cout << array[j] << " ";
				}
			}
			array[loc + 1] = newItem;
		}
	}

	if (cnt < k + 1) {
		cout << -1;
	}

	delete array;

	return 0;
}

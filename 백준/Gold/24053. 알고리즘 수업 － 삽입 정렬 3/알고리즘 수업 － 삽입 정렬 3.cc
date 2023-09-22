#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, temp;
	cin >> n;

	int* array = new int[n];
	int* array2 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> temp;
		array[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		array2[i] = temp;
	}

	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (equal(array, array + n, array2)) {
			cout << 1;
			flag = true;
			break;
		}

		int loc = i - 1;
		int newItem = array[i];

		for (; loc > -1 && array[loc] > newItem; loc--) {
			array[loc + 1] = array[loc];
			if (equal(array, array + n, array2)) {
				cout << 1;
				flag = true;
				break;
			}
		}

		if (flag) break;

		if (loc != i - 1) {
			array[loc + 1] = newItem;
			if (equal(array, array + n, array2)) {
				cout << 1;
				flag = true;
				break;
			}
		}

		if (flag) break;
	}

	if (!flag) cout << 0;

	delete array, array2;

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int* array = new int[n];

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		array[i] = temp;
	}

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;

		for (int j = 0; j < n - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				swapped = true;
				cnt++;
				if (cnt == k) {
					for (int k = 0; k < n; k++) {
						cout << array[k] << " ";
					}

					break;
				}
			}
		}

		if (swapped == false)
			break;
	}

	if (cnt < k) {
		cout << -1;
	}

	delete array;

	return 0;
}

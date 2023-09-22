#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int n, int* array, int target);

int main()
{
	int n, temp;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> temp;
		array[i] = temp;
	}

	int m;
	cin >> m;
	int* array2 = new int[m];

	for (int i = 0; i < m; i++) {
		cin >> temp;
		array2[i] = temp;
	}

	sort(array, array + n);

	for (int i = 0; i < m; i++) {
		printf("%d\n", BinarySearch(n, array, array2[i]));
	}

	delete array, array2;

	return 0;
}

int BinarySearch(int n, int* array, int target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		if (target < array[middle]) {
			right = middle - 1;
		} 
		else if (target > array[middle]) {
			left = middle + 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}
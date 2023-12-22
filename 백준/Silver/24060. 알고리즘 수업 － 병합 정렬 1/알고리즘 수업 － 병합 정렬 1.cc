#include <iostream>

using namespace std;

int k, cnt = 0;

void merge(int* arr, int start, int middle, int end, int* tmp) {
	int i = start, j = middle + 1, t = 0;
	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}
	while (i <= middle) {
		tmp[t++] = arr[i++];
	}
	while (j <= end) {
		tmp[t++] = arr[j++];
	}
	i = start;
	t = 0;
	while (i <= end) {
		cnt++;
		if (cnt == k) {
			cout << tmp[t];
		}
		arr[i++] = tmp[t++];
	}
}

void merge_sort(int* arr, int start, int end, int* tmp) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(arr, start, middle, tmp);
		merge_sort(arr, middle + 1, end, tmp);
		merge(arr, start, middle, end, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n >> k;

	int* arr = new int[n];
	int* tmp = new int[n];
	for (int i = 0; i < n; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1, tmp);

	if (cnt < k) {
		cout << -1 << '\n';
	}

	delete[] arr;

	return 0;
}
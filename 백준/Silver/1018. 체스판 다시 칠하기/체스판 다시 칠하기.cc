#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, m, min = 64;
	cin >> n >> m;

	string* arr = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int x = 0; x < m - 7; x++) {
		for (int y = 0; y < n - 7; y++) {
			int b_start_count = 0;
			int w_start_count = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (i % 2 == 0) {
						if (j % 2 == 0) {
							if (arr[y + i][x + j] == 'B') {
								w_start_count++;
							}
							else {
								b_start_count++;
							}
						}
						else {
							if (arr[y + i][x + j] == 'B') {
								b_start_count++;
							}
							else {
								w_start_count++;
							}
						}
					}
					else {
						if (j % 2 == 0) {
							if (arr[y + i][x + j] == 'B') {
								b_start_count++;
							}
							else {
								w_start_count++;
							}
						}
						else {
							if (arr[y + i][x + j] == 'B') {
								w_start_count++;
							}
							else {
								b_start_count++;
							}
						}
					}
				}
			}
			int less_count = w_start_count > b_start_count ? b_start_count : w_start_count;
			if (less_count < min) {
				min = less_count;
			}
		}
	}

	cout << min;

	delete[] arr;

	return 0;
}
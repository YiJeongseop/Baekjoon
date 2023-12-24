#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10] = { 0, };

	int n;
	cin >> n;

	string number = to_string(n);

	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '0') {
			arr[0]++;
		}
		else if (number[i] == '1') {
			arr[1]++;

		}
		else if (number[i] == '2') {
			arr[2]++;

		}
		else if (number[i] == '3') {
			arr[3]++;

		}
		else if (number[i] == '4') {
			arr[4]++;

		}
		else if (number[i] == '5') {
			arr[5]++;

		}
		else if (number[i] == '6') {
			if (arr[6] > arr[9]) {
				arr[9]++;
			}
			else {
				arr[6]++;
			}
		}
		else if (number[i] == '7') {
			arr[7]++;

		}
		else if (number[i] == '8') {
			arr[8]++;
		}
		else if (number[i] == '9') {
			if (arr[6] < arr[9]) {
				arr[6]++;
			}
			else {
				arr[9]++;
			}
		}
	}

	sort(arr, arr + 10);
	cout << arr[9];

	return 0;
}
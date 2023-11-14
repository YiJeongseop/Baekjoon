#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x;
	cin >> x;

	if (x == 1) {
		cout << "1/1";
		return 0;
	}

	// 1 23 456 78910 1112131415
	int start = 2;
	int end = 3;
	int num = 2;
	while (true) {
		if (x >= start && x <= end) {
			if (num % 2 == 0) {
				int temp = x - start;
				cout << 1 + temp << "/" << num - temp;
			}
			else {
				int temp = x - start;
				cout << num - temp << "/" << 1 + temp;
			}
			return 0;
		}
		start = end + 1;
		num++;
		end += num;
	}

	return 0;
}
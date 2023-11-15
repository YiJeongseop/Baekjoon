#include <iostream>

using namespace std;

int main() {
	int n, x, y, max_x, min_x, max_y, min_y;
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		if (i == 0) {
			max_x = x; min_x = x;
			max_y = y; min_y = y;
		}
		else {
			max_x = x >= max_x ? x : max_x;
			min_x = x < min_x ? x : min_x;
			max_y = y >= max_y ? y : max_y;
			min_y = y < min_y ? y : min_y;
		}
	}
 
	cout << (max_x - min_x) * (max_y - min_y);

	return 0;
}
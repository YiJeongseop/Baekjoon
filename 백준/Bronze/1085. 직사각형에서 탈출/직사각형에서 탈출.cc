#include <iostream>

using namespace std;

int main() {
	int x, y, w, h, result;
	cin >> x >> y >> w >> h;

	result = w - x;
	if (x < result) result = x;
	if (y < result) result = y;
	if (h - y < result) result = h - y;

	cout << result;
 
	return 0;
}
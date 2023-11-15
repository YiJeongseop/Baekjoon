#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int side[3];
	
	for (int i = 0; i < 3; i++) {
		cin >> side[i];
	}

	sort(side, side + 3);

	if (side[2] >= (side[1] + side[0])) {
		side[2] = side[1] + side[0] - 1;
	}
	cout << side[0] + side[1] + side[2];

	return 0;
}
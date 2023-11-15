#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int side[3];

	while (true) {
		for (int i = 0; i < 3; i++) {
			cin >> side[i];
		}
		if (side[0] == 0 && side[1] == 0 && side[2] == 0) {
			break;
		}
		sort(side, side + 3);
		
		if (side[2] >= side[0] + side[1]) {
			cout << "Invalid" << '\n';
		}
		else if (side[0] == side[1] && side[1] == side[2]) {
			cout << "Equilateral" << '\n';
		}
		else if (side[0] != side[1] && side[1] != side[2] && side[0] != side[2]) {
			cout << "Scalene" << '\n';
		}
		else {
			cout << "Isosceles" << '\n';
		}
	}

	return 0;
}
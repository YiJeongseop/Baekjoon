#include <iostream>

using namespace std;

int main() {
	int angle1, angle2, angle3;
	cin >> angle1 >> angle2 >> angle3;

	if (angle1 == 60 && angle2 == 60 && angle3 == 60) {
		cout << "Equilateral";
	}
	else if (angle1 + angle2 + angle3 == 180) {
		if (angle1 != angle2 && angle1 != angle3 && angle2 != angle3) {
			cout << "Scalene";
		}
		else {
			cout << "Isosceles";
		}
	}
	else {
		cout << "Error";
	}

	return 0;
}
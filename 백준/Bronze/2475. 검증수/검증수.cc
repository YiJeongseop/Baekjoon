#include <iostream>

using namespace std;

int main() {
	int one, two, three, four, five;
	cin >> one >> two >> three >> four >> five;

	cout << (one * one + two * two + three * three + four * four + five * five) % 10;

	return 0;
}
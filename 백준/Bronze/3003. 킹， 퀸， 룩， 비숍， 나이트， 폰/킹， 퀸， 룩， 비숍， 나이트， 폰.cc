#include <iostream>
#include <string>

using namespace std;

int main() {
	unsigned short answer[6] = {1, 1, 2, 2, 2, 8};
	unsigned short input[6];

	for (int i = 0; i < 6; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++) {
		cout << answer[i] - input[i] << " ";
	}

	return 0;
}
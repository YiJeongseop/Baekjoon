#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string n;
	int b, result = 0;

	cin >> n >> b;

	for (int i = 0; i < n.length(); i++) {
		if (n[n.length() - 1 - i] - 'A' >= 0 && n[n.length() - 1 - i] - 'A' <= 25) {
			result += (((n[n.length() - 1 - i] - 'A') + 10) * pow(b, i));
			//cout << "First case : " << ((n[n.length() - 1 - i] - 'A') + 10) << " " << pow(b, i) << "\n";
			//cout << (((n[n.length() - 1 - i] - 'A') + 10) * pow(b, i)) << "\n";
		}
		else {
			result += ((n[n.length() - 1 - i] - '0') * pow(b, i));
			//cout << "Second case : " << n[n.length() - 1 - i] - '0' << " " << pow(b, i) << "\n";
			//cout << ((n[n.length() - 1 - i] - '0') * pow(b, i)) << "\n";
		}
	}

	cout << result;

	return 0;
}
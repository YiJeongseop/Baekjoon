#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	string reverse_a = "   ";
	string reverse_b = "   ";

	string str_a = to_string(a);
	string str_b = to_string(b);

	for (int i = 0; i < 3; i++) {
		reverse_a[i] = str_a[2 - i];
		reverse_b[i] = str_b[2 - i];
	}

	if (stoi(reverse_a) > stoi(reverse_b)) {
		cout << stoi(reverse_a);
	}
	else {
		cout << stoi(reverse_b);
	}

	return 0;
}
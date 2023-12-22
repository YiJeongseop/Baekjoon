#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long a) {
	if (a == 0 || a == 1) return 1;
	else return a * factorial(a - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long n;
	cin >> n;

	cout << factorial(n);

	return 0;
}
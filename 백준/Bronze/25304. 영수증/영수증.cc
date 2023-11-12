#include <iostream>

int main()
{
	unsigned int x, a;
	unsigned short n, b;
	unsigned int sum = 0;

	std::cin >> x;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> a;
		std::cin >> b;
		sum += a * b;
	}

	if (sum == x) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

	return 0;
}
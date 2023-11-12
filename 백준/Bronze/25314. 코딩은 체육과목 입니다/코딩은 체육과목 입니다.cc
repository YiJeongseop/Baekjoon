#include <iostream>

int main()
{
	unsigned short n;

	std::cin >> n;
	std::cout << "long";
	
	for (int i = 0; i < n / 4 - 1; i++) {
		std::cout << " long";
	}

	std::cout << " int";

	return 0;
}
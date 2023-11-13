#include <iostream>
#include <string>

int main()
{
	unsigned short t;
	std::string str;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> str;
		std::cout << str[0] << str[str.length() - 1] << std::endl;
	}

	return 0;
}
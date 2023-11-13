#include <iostream>

int main()
{
	char str[1001];
	unsigned short i;
	std::cin >> str >> i;

	std::cout << str[i - 1];

	return 0;
}
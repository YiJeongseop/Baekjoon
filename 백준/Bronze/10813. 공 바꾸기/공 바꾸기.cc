#include <iostream>

int main()
{
	unsigned short n, m;

	std::cin >> n >> m;

	unsigned short* array = new unsigned short[n];

	for (int i = 0; i < n; i++) {
		array[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		unsigned short basket1, basket2;
		std::cin >> basket1 >> basket2;
		
		unsigned short temp = array[basket1 - 1];
		array[basket1 - 1] = array[basket2 - 1];
		array[basket2 - 1] = temp;
	}

	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}

	delete[] array;

	return 0;
}
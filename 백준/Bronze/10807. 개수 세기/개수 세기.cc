#include <iostream>

int main()
{
	unsigned short n;
	short v;

	std::cin >> n;

	short* array = new short[n];
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}

	std::cin >> v;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == v) {
			count++;
		}
	}

	std::cout << count;

	delete[] array;

	return 0;
}
#include <iostream>

int main()
{
	unsigned short n, m;

	std::cin >> n >> m;

	unsigned short* array = new unsigned short[n];
	unsigned short* temp_arr;

	for (int i = 0; i < n; i++) {
		array[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		unsigned short basket1, basket2;
		std::cin >> basket1 >> basket2;

		temp_arr = new unsigned short[basket2 - basket1 + 1];

		int index = 0;
		for (int j = basket2 - 1; j > basket1 - 2; j--) {
			temp_arr[index] = array[j];
			index++;
		}

		index = 0;
		int index2 = basket1 - 1;
		for (index; index < basket2 - basket1 + 1; index++) {
			array[index2] = temp_arr[index];
			index2++;
		}

		delete[] temp_arr;
	}

	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}

	delete[] array;

	return 0;
}
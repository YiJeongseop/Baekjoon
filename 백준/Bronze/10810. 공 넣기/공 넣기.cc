#include <iostream>

int main()
{
	unsigned short n, m;

	std::cin >> n >> m;

	unsigned short* array = new unsigned short[n];

	std::fill_n(array, n, 0);

	for (int i = 0; i < m; i++) {
		unsigned short first, last, num_of_ball;
		std::cin >> first >> last >> num_of_ball;
		
		for (int j = first - 1; j < last; j++) {
			array[j] = num_of_ball;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}

	delete[] array;

	return 0;
}
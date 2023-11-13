#include <iostream>

using namespace std;

int main() {
	int matrix[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> matrix[i][j];
		}
	}

	int max = -1;
	int row, col;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
				row = i + 1; col = j + 1;
			}
		}
	}

	cout << max << endl << row << " " << col;

	return 0;
}
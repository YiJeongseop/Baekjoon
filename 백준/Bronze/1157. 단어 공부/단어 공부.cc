#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int alphabet[26] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		alphabet[toupper(str[i]) - 'A'] += 1;
	}

	int max = -1;
	int index_of_max = -1;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			index_of_max = i;
		}
	}

	int overlap_check = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max) {
			overlap_check++;
		}
	}

	if (overlap_check == 1) {
		cout << (char)(65 + index_of_max);
	}
	else {
		cout << "?";
	}

	return 0;
}
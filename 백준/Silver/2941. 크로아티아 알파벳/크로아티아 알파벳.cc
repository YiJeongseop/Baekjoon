#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c' || str[i] == 'z' || str[i] == 's') {
			if (str[i + 1] == '=') {
				str.replace(i, 2, "#");
			}
			else if (str[i + 1] == '-' && str[i] == 'c') {
				str.replace(i, 2, "#");
			}
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == '-') {
				str.replace(i, 2, "#");
			}
			else if (str[i + 1] == 'z' && str[i + 2] == '=') {
				str.replace(i, 3, "#");
			}
		}
		else if (str[i] == 'l' || str[i] == 'n') {
			if (str[i + 1] == 'j') {
				str.replace(i, 2, "#");
			}
		}
	}

	cout << str.length();

	return 0;
}
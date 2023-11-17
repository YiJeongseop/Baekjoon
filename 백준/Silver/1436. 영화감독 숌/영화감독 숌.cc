#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, count = 1;
	cin >> n;

	int num = 666;
	while (count != n) {
		num++;
		string num_str = to_string(num);
		for (int i = 0; i < num_str.length() - 2; i++) {
			if (num_str[i] == '6' && num_str[i + 1] == '6' && num_str[i + 2] == '6') {
				count++;
				break;
			}
		}
	}
	cout << num;

	return 0;
}
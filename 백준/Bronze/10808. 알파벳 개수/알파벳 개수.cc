#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[26] = { 0, };

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		arr[(int)str[i] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

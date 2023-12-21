#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int num1, int num2) {
	if (num2 == 0) return num1;
	else return gcd(num2, num1 % num2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, temp1, temp2, gcd_value;
	cin >> n;

	int* arr = new int[n - 1];

	cin >> temp1;
	for (int i = 0; i < n - 1; i++) {
		cin >> temp2;
		arr[i] = temp2 - temp1;
		temp1 = temp2;
	}

	gcd_value = gcd(arr[0], arr[1]);
	for (int i = 2; i < n - 1; i++) {
		gcd_value = gcd(gcd_value, arr[i]);
	}

	int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		answer += arr[i] / gcd_value - 1;
	}

	cout << answer;

	delete[] arr;

	return 0;
}

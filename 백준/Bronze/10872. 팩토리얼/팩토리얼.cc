#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int answer = 1;

	for (int i = n; i > 0; i--) {
		answer *= i;
	}
	
	cout << answer;

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, value, Y = 0, M = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> value;
		Y += ((value / 30) + 1) * 10;
		M += ((value / 60) + 1) * 15;
	}

	if (Y == M) {
		cout << "Y M " << Y;
	}
	else if (Y < M) {
		cout << "Y " << Y;
	}
	else {
		cout << "M " << M;
	}

	return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, done = 0;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<int> s;
	string str = "";
	s.push(1);
	str += "+";

	for (int i = 2; i < n + 1; i++) {
		while (s.top() == arr[done]) {
			s.pop();
			str += "-";
			done++;
			if (s.empty()) break;
		}
		s.push(i);
		str += "+";
	}

	while (done != n) {
		if (s.top() == arr[done]) {
			s.pop();
			str += "-";
			done++;
		}
		else if (s.top() > arr[done]) {
			cout << "NO";
			return 0;
		}
	}

	for (char c : str) {
		cout << c << '\n';
	}

	delete[] arr;

	return 0;
}
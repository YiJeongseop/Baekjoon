#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, num;
	cin >> k;

	stack<int> s;

	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	int sum = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}
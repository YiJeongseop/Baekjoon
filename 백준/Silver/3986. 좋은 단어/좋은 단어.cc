#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, sum = 0;
	cin >> N;

	string str;

	while (N--) {
		cin >> str;
		stack<char> s;
		for (char c : str) {
			if (!s.empty() && s.top() == c) {
				s.pop();
			}
			else {
				s.push(c);
			}
		}
		if (s.empty()) {
			sum++;
		}
	}

	cout << sum;

	return 0;
}
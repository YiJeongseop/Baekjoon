#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, student;
	cin >> n;

	stack<int> s1;
	stack<int> s2;
	int s1_num = 1;

	for (int i = 0; i < n; i++) {
		cin >> student;
		if (student == s1_num) {
			s1.push(student);
			s1_num++;
		}
		else {
			if (!s2.empty()) {
				while (s2.top() == s1_num) {
					s1.push(s2.top());
					s1_num++;
					s2.pop();
					if (s2.empty()) {
						break;
					}
				}
			}
			s2.push(student);
		}
	}

	if (!s2.empty()) {
		while (s2.top() == s1_num) {
			s1.push(s2.top());
			s1_num++;
			s2.pop();
			if (s2.empty()) {
				break;
			}
		}
	}

	if (s2.empty()) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}

	return 0;
}
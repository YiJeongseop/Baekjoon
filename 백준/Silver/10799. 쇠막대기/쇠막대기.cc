#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int sum = 0;
	string str;
	cin >> str;

	stack<tuple<int, char, int>> s;

	int index = 0;
	for (char c : str) {
		if (s.empty()) {
			s.push(make_tuple(index, c, 0));
		}
		else if(get<0>(s.top()) == index - 1 && get<1>(s.top()) == '(' && c == ')') {
			s.pop();
		}
		else if (get<1>(s.top()) == '(' && c == ')') {
			sum += (index - get<0>(s.top()) - get<2>(s.top()) * 2) / 2 + 1;
			// cout << "현재 index는 " << index << "이며, sum은 " << sum << "입니다." << '\n';
			int temp = get<2>(s.top());
			s.pop();
			if (!s.empty() && get<1>(s.top()) == '(') {
				get<2>(s.top())+= temp + 1;
			}
		}
		else {
			s.push(make_tuple(index, c, 0));
		}
		index++;
	}

	cout << sum;

	return 0;
}
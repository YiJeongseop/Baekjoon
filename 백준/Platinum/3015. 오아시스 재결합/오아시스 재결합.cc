#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<pair<int, int>> s;
	int N, P;
	unsigned long long sum = 0;
	cin >> N;

	while (N--) {
		bool flag = false;
		int pop_same_count = 0;
		cin >> P;
		// cout << P << "가 들어갔습니다." << '\n';
		if (s.empty()) {
			s.push(make_pair(P, 0));
			continue;
		}
		while (!s.empty() && s.top().first <= P) {
			if (s.top().first == P) {
				pop_same_count++;
				pop_same_count += s.top().second;
			}
			sum += s.top().second;
			// cout << "sum이 +s.top().second 되었습니다. : " << sum << '\n';
			s.pop();
			sum++;
			// cout << "sum이 +1 되었습니다. : " << sum << '\n';
			if (s.empty()) {
				s.push(make_pair(P, pop_same_count));
				flag = true;
				break;
			}
		}
		if (flag) continue;
		sum++;
		// cout << "sum이 +1 되었습니다. : " << sum << '\n';
		s.push(make_pair(P, pop_same_count));
	}

	cout << sum;

	return 0;
}
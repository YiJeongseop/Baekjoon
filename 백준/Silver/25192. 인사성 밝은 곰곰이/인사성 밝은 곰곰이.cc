#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt = 0;
	cin >> n;

	string str;
	set<string> s;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "ENTER") {
			s.clear();
		}
		else if (s.find(str) == s.end()) {
			cnt++;
			s.insert(str);
		}
	}

	cout << cnt;

	return 0;
}
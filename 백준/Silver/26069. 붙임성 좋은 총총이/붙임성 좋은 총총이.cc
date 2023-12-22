#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str, str2;
	set<string> s;
	s.insert("ChongChong");

	for (int i = 0; i < n; i++) {
		cin >> str >> str2;
		if (s.find(str) != s.end()) {
			s.insert(str2);
		}
		else if (s.find(str2) != s.end()) {
			s.insert(str);
		}
	}

	cout << s.size();

	return 0;
}
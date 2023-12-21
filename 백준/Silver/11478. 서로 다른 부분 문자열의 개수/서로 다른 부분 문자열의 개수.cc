#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, temp;
	set<string> s_set;

	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length() - i; j++) {
			temp = s.substr(i, j + 1);
			s_set.insert(temp);
		}
	}

	cout << s_set.size();

	return 0;
}

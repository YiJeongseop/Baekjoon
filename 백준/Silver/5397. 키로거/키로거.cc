#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		list<char> L;
		list<char>::iterator t = L.end();
		for (char s : str) {
			if (s == '<') {
				if(t != L.begin()) t--;
			}
			else if (s == '>') {
				if(t != L.end()) t++;
			}
			else if (s == '-') {
				if (t != L.begin()) {
					t--;
					t = L.erase(t);
				}
			}
			else {
				if (t != L.end()) {
					L.insert(t, s);
				}
				else {
					L.push_back(s);
					t = L.end();
				}
			}
		}

		for (char s : L) {
			cout << s;
		}
		cout << '\n';
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	map<string, string> m;
	string name, message;

	for (int i = 0; i < n; i++) {
		cin >> name >> message;
		if (message == "enter") {
			m.insert({ name, message });
		}
		else {
			m.erase(name);
		}
	}

	for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
		cout << iter->first << '\n';
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> m1;
	vector<string> v;
	string name, value;

	for (int i = 1; i < n + 1; i++) {
		cin >> name;
		m1.insert({ name, i });
		v.push_back(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> value;
		if (value[0] >= 65 && value[0] <= 90) {
			cout << m1[value] << '\n';
		}
		else {
			cout << v.at(stoi(value) - 1) << '\n';
		}
	}

	return 0;
}

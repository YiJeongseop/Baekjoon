#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> s;
	string name;

	for (int i = 0; i < n; i++) {
		cin >> name;
		s.insert(name);
	}

	vector<string> sv;

	for (int i = 0; i < m; i++) {
		cin >> name;
		if (s.find(name) != s.end()) {
			sv.push_back(name);
		}
	}

	sort(sv.begin(), sv.end());

	cout << sv.size() << '\n';
	for (auto& i : sv) {
		cout << i << '\n';
	}

	return 0;
}

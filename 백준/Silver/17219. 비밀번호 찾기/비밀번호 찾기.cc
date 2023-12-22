#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> ma;

	string name, pw;

	for (int i = 0; i < n; i++) {
		cin >> name >> pw;
		ma[name] = pw;
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		cout << ma[name] << '\n';
	}

	return 0;
}
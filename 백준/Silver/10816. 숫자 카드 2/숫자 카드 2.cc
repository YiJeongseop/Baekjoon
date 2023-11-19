#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, temp;
	cin >> n;

	map<int, int> m1;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (m1.find(temp) != m1.end()) {
			m1.find(temp)->second++;
		}
		else{
			m1.insert({ temp, 1 });
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << m1[temp] << " ";
	}

	return 0;
}
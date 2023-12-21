#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a_count, b_count;
	cin >> a_count >> b_count;

	int value;
	
	set<int> a, b;

	for (int i = 0; i < a_count; i++) {
		cin >> value;
		a.insert(value);
	}

	int union_count = 0;

	for (int i = 0; i < b_count; i++) {
		cin >> value;
		if (a.find(value) != a.end()) {
			union_count++;
		}
		b.insert(value);
	}

	cout << a.size() - union_count + b.size() - union_count;

	return 0;
}
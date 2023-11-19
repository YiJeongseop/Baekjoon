#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(tuple<int, string, int>& p1, tuple<int, string, int>& p2);

int main() {
	int n, age;
	string name;
	cin >> n;

	vector<tuple<int, string, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back(make_tuple(age, name, i));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << '\n';
	}
		
	return 0;
}

bool cmp(tuple<int, string, int>& p1, tuple<int, string, int>& p2) {
	if (get<0>(p1) == get<0>(p2)) {
		return get<2>(p1) < get<2>(p2);
	}
	else {
		return get<0>(p1) < get<0>(p2);
	}
}
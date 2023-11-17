#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<string, int>& p1, pair<string, int>& p2);

int main() {
	int n;
	string str;
	cin >> n;

	vector<pair<string, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(make_pair(str, str.length()));
	}

	sort(v.begin(), v.end(), cmp);

	vector<pair<string, int>>::iterator uit = unique(v.begin(), v.end());

	v.erase(uit, v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).first << '\n';
	}
		
	return 0;
}

bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}
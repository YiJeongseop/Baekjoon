#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2);

int main() {
	int n, temp1, temp2;
	cin >> n;

	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		v.push_back({ temp1, temp2 });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).at(0) << " " << v.at(i).at(1) << '\n';
	}
		
	return 0;
}

bool cmp(vector<int>& v1, vector<int>& v2) {
	if (v1[1] == v2[1]) {
		return v1[0] < v2[0];
	}
	else {
		return v1[1] < v2[1];
	}
}
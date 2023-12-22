#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
map<string, int> ma;

bool compare(string& a, string& b) {
	if (ma[a] == ma[b] && a.length() == b.length()) {
		return a < b;
	}
	else if (ma[a] == ma[b]) {
		return a.length() > b.length();
	}
	else {
		return ma[a] > ma[b];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cnt = 0;
	cin >> n >> m;

	string str;
	string* arr = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (ma.find(str) == ma.end() && str.length() >= m) {
			ma.insert({str, 1});
			arr[cnt++] = str;
		}
		else if(str.length() >= m) {
			ma[str] += 1;
		}
	}

	sort(arr, arr + cnt, compare);

	for (int i = 0; i < cnt; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
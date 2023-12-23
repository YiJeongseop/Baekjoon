#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void hanoi_tower(int num, int from, int by, int to) {
	if (num == 1) {
		// cout << from << " " << to << '\n';
		v.push_back(make_pair(from, to));
		cnt++;
	}
	else {
		hanoi_tower(num - 1, from, to, by);
		// cout << from << " " << to << '\n';
		v.push_back(make_pair(from, to));
		cnt++;
		hanoi_tower(num - 1, by, from, to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	hanoi_tower(n, 1, 2, 3);

	cout << cnt << '\n';

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}
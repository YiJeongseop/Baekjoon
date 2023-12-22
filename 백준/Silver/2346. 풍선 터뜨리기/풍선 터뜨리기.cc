#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, temp;
	cin >> n;

	pair<int, int> p;
	deque<pair<int, int>> d;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		p = make_pair(i + 1, temp);
		d.push_back(p);
	}

	p = d.front();
	d.pop_front();
	cout << p.first << " ";

	while (!d.empty()) {
		int temp = p.second;
		if (p.second > 0) {
			for (int i = 0; i < temp - 1; i++) {
				p = d.front();
				d.pop_front();
				d.push_back(p);
			}
			p = d.front();
			d.pop_front();
			cout << p.first << " ";
		}
		else {
			for (int i = 0; i > temp + 1; i--) {
				p = d.back();
				d.pop_back();
				d.push_front(p);
			}
			p = d.back();
			d.pop_back();
			cout << p.first << " ";
		}
	}

	return 0;
}
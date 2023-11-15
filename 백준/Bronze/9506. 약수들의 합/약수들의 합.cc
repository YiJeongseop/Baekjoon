#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;

	cin >> n;
	while (n != -1) {
		int sum = 1;
		vector<int> v;
		v.push_back(1);
		for (int i = 2; i <= (int)sqrt(n); i++) {
			if (n % i == 0) {
				sum += i;
				v.push_back(i);
				if (i != n / i) {
					sum += n / i;
					v.push_back(n / i);
				}
			}
		}
		if (sum != n) {
			cout << n << " is NOT perfect." << endl;
		}
		else {
			sort(v.begin(), v.end());
			cout << n << " = ";
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] << endl;
		}
		cin >> n;
	}

	return 0;
}
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	while (T--) {
		string P, X;
		int n;

		cin >> P >> n >> X;

		if (n == 0) {
			bool flag = false;
			for (char c : P) {
				if (c == 'D') {
					flag = true;
					cout << "error" << '\n';
					break;
				}
			}
			if (flag) continue;
			else {
				cout << "[]" << '\n';
				continue;
			}
		}

		int* arr = new int[X.length()];
		
		for (int i = 0; i < X.length(); i++) {
			arr[i] = 0;
		}

		X = X.substr(1, X.length() - 2);

		int cur_position = 0;
		int position;

		// cout << X << "\n";

		int i = 0;
		while ((position = X.find(",", cur_position)) != string::npos) {
			int len = position - cur_position;
			string result = X.substr(cur_position, len);
			arr[i++] = stoi(result);
			cur_position = position + 1;
		}
		string result = X.substr(cur_position);
		arr[i] = stoi(result);

		deque<int> dq;

		i = 0;
		while (arr[i] != 0) {
			dq.push_back(arr[i]);
			i++;
		}

		bool flag = false;

		int reverse_count = 0;

		for (char c : P) {
			if (c == 'R') {
				reverse_count++;
			}
			else {
				if (dq.empty()) {
					cout << "error" << '\n';
					flag = true;
					break;
				}
				else {
					if (reverse_count % 2 == 0) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}

		if (flag) continue;

		if (reverse_count % 2 == 1) {
			reverse(dq.begin(), dq.end());
		}

		cout << "[";
		int temp = dq.size();
		for (int i = 0; i < temp; i++) {
			cout << dq.front();
			dq.pop_front();
			if (i == temp - 1) {
				break;
			}
			cout << ",";
		}
		cout << "]" << '\n';

		delete[] arr;
	}

	return 0;
}
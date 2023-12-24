#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<pair<int, int>> s;
	int N, A;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A;
		arr[i] = -1;
		int count = 1;
		while (!s.empty()) {
			if (s.top().second < A) {
				arr[s.top().first] = A;
				s.pop();
				count++;
			}
			else {
				break;
			}
		}
		s.push(make_pair(i, A));
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<pair<int, long long>> s;
	long long N, sum = 0;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[N - 1 - i];
	}

	for (int i = 0; i < N; i++) {
		int remove_count = 0;
		while (!s.empty()) {
			if (arr[i] > s.top().first) {
				sum++;
				sum+= s.top().second;
				remove_count++;
				remove_count += s.top().second;
				s.pop();
			}
			else {
				break;
			}
		}
		s.push(make_pair(arr[i], remove_count));
	}

	cout << sum;

	delete[] arr;

	return 0;
}
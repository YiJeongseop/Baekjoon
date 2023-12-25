#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int firstZeroReturn(int* arr, int size) {
	for (int i = 1; i <= size; i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
}

int lastZeroReturn(int* arr, int size) {
	for (int i = size; i > 0; i--) {
		if (arr[i] == 0) {
			return i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, value, count = 0;
	cin >> N >> M;

	int arr[51] = { 0, };

	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> value;
		if (dq.front() == value) {
			dq.pop_front();
			arr[value] = 1;
		}
		else {
			bool check = false;
			int value1_count = 0;
			int value2_count = 0;
			int current_value1 = dq.front();
			// cout << "current_value1 처음 : " << dq.front() << '\n';
			int current_value2 = dq.front();
			// cout << "current_value2 처음 : " << dq.front() << '\n';
			int firstZeroIndex = firstZeroReturn(arr, N);
			// cout << "firstZeroIndex : " << firstZeroIndex << '\n';
			int lastZeroIndex = lastZeroReturn(arr, N);
			// cout << "lastZeroIndex : " << lastZeroIndex << '\n';
			while (true) {
				current_value1++;
				// cout << "current_value1 : " << current_value1 << '\n';
				if (current_value1 == lastZeroIndex + 1) {
					current_value1 = firstZeroIndex;
				}
				while (arr[current_value1] == 1) {
					current_value1++;
					if (current_value1 == N + 1) {
						current_value1 = firstZeroIndex;
					}
				}
				value1_count++;
				current_value2--;
				// cout << "current_value2 : " << current_value2 << '\n';
				if (current_value2 == firstZeroIndex - 1) {
					current_value2 = lastZeroIndex;
				}
				while (arr[current_value2] == 1) {
					current_value2--;
					if (current_value2 == firstZeroIndex - 1) {
						current_value2 = lastZeroIndex;
					}
				}
				value2_count++;
				if (current_value1 == value) {
					check = true;
					break;
				}
				else if (current_value2 == value) {
					check = false;
					break;
				}
			}
			if (check) {
				count += value1_count;
				// cout << value1_count << "를 더했습니다! value1_count" << '\n';
				for (int i = 0; i < value1_count; i++) {
					int temp = dq.front();
					dq.pop_front();
					dq.push_back(temp);
				}
				dq.pop_front();
				arr[value] = 1;
			}
			else {
				count += value2_count;
				// cout << value2_count << "를 더했습니다! value2_count" << '\n';
				for (int i = 0; i < value2_count; i++) {
					int temp = dq.back();
					dq.pop_back();
					dq.push_front(temp);
				}
				dq.pop_front();
				// cout << dq.front() << "더한 다음 위치는?" << '\n';
				arr[value] = 1;
			}
		}
	}

	cout << count;

	return 0;
}
#include <iostream>

using namespace std;

int N;
int arr[2187][2187];
int answer[3];

void func(int n, pair<int, int> start, pair<int, int> end) {
    if (n == 1) {
        answer[arr[start.first][start.second] + 1]++;
        return;
    }
    else {
        bool flag = false;
        int temp = arr[start.first][start.second];
        for (int y = start.first; y <= end.first; y++) {
            for (int x = start.second; x <= end.second; x++) {
                if (temp != arr[y][x]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) {
            int temp2 = (end.first - start.first + 1) / 3;
            for (int y = start.first; y <= end.first; y+= temp2) {
                for (int x = start.second; x <= end.second; x+= temp2) {
                    func(n - 1, { y, x }, { y + temp2 - 1, x + temp2 - 1 });
                }
            }
        }
        else {
            answer[temp + 1]++;
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> arr[y][x];
        }
    }

    func(N, { 0, 0 }, {N - 1, N - 1});

    cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];

    return 0;
}
#include <iostream>

using namespace std;

int N;
int paper[128][128];
int answer[2];

void func(int n, pair<int, int> start, pair<int, int> end) {
    if (n == 1) {
        answer[paper[start.first][start.second]]++;
        return;
    }
    else {
        bool flag = false;
        int temp = paper[start.first][start.second];
        for (int y = start.first; y <= end.first; y++) {
            for (int x = start.second; x <= end.second; x++) {
                if (temp != paper[y][x]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) {
            int temp2 = (end.first - start.first + 1) / 2;
            for (int y = start.first; y <= end.first; y += temp2) {
                for (int x = start.second; x <= end.second; x += temp2) {
                    func(n / 2, { y, x }, { y + temp2 - 1, x + temp2 - 1 });
                }
            }
        }
        else {
            answer[temp]++;
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
            cin >> paper[y][x];
        }
    }

    func(N, { 0, 0 }, { N - 1, N - 1 });

    cout << answer[0] << '\n' << answer[1];

    return 0;
}
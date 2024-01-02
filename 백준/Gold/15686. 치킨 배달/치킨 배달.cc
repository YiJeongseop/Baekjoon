#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

int N, M;
int board[50][50];
vector<tuple<int, int, int>> chicken;
vector<pair<int, int>> house;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int order = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
            if (board[y][x] == 2) {
                chicken.push_back({ y, x, order++ });
            }
            else if (board[y][x] == 1) {
                house.push_back({ y, x });
            }
        }
    }

    int chicken_count = chicken.size();
    int* mask = new int[chicken_count];

    fill(mask, mask + chicken_count, 0);
    for (int i = 0; i < M; i++) {
        mask[chicken_count - 1 - i] = 1;
    }

    int sum, ans = INT_MAX;

    do {
        sum = 0;
        for (auto& house_ : house) {
            int hy, hx;
            tie(hy, hx) = house_;
            int dis = INT_MAX;
            for (auto& chicken_ : chicken) {
                int y, x, num;
                tie(y, x, num) = chicken_;
                if (!mask[num]) continue;
                dis = min(dis, abs(hy - y) + abs(hx - x));
            }
            sum += dis;
        }
        ans = min(ans, sum);
    } while (next_permutation(mask, mask + chicken_count));

    cout << ans;

    delete[] mask;

    return 0;
}
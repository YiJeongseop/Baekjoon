#include <iostream>
#include <vector>

using namespace std;

int N, tmp;
int half = 1000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(2000001);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v[tmp + half]++;
    }

    for (int i = 0; i < 2000001; i++) {
        while (v[i] > 0) {
            cout << i - half << '\n';
            v[i]--;
        }
    }

    return 0;
}
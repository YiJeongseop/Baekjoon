#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N;
int arr[21][21];
int mask[21];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> arr[y][x];
        }
    }

    for (int i = N; i > N / 2; i--) {
        mask[i] = 1;
    }

    int ans = INT_MAX;

    do {
        int s1 = 0, s2 = 0;
        vector<int> v1, v2;
        for (int i = 1; i <= N; i++) {
            if (mask[i]) v1.push_back(i);
            else v2.push_back(i);
        }

        for (int i = 0; i < v1.size(); i++) {
            //cout << "v1에서 " << v1[i] << "를 꺼냈습니다. " << '\n';
            for (int j = i + 1; j < v1.size(); j++){
                //cout << "v1에서 " << v1[j] << "를 꺼냈습니다. " << '\n';
                s1 += arr[v1[i]][v1[j]];
                s1 += arr[v1[j]][v1[i]];
            }
        }

        for (int i = 0; i < v2.size(); i++) {
            //cout << "v2에서 " << v2[i] << "를 꺼냈습니다. " << '\n';
            for (int j = i + 1; j < v2.size(); j++) {
                //cout << "v2에서 " << v2[j] << "를 꺼냈습니다. " << '\n';
                s2 += arr[v2[i]][v2[j]];
                s2 += arr[v2[j]][v2[i]];
            }
        }

        ans = min(ans, abs(s1 - s2));
    } while (next_permutation(mask + 1, mask + N + 1));

    cout << ans;

    return 0;
}
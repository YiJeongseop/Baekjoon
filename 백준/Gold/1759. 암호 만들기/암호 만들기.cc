#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[16];
int arr2[16];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    fill(arr2, arr2 + C, 0);
    for (int i = L; i < C; i++) {
        arr2[i] = 1;
    }

    sort(arr, arr + C);

    do {
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < C; i++) {
            if (!arr2[i]) {
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    count++;
                }
                else {
                    count2++;
                }
            }
        }
        if (count == 0 || count2 <= 1) continue;
        for (int i = 0; i < C; i++) {
            if (!arr2[i]) cout << arr[i];
        }
        cout << '\n';
    } while (next_permutation(arr2, arr2 + C));

    return 0;
}
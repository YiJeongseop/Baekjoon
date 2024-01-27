#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[20005][5];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp;
    cin >> N;
    tmp = N / 5;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '#') arr[i % tmp][i / tmp] = 1;
        else arr[i % tmp][i / tmp] = 0;
    }

    int pos = 0;
    while (pos < tmp) {
        if (arr[pos][0] == 0) {
            pos++;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 1 && arr[pos][2] == 1 && arr[pos][3] == 1 && arr[pos][4] == 1 && arr[pos + 1][0] == 1 && arr[pos + 1][2] == 0) {
            cout << 0;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 1 && arr[pos][2] == 1 && arr[pos][3] == 1 && arr[pos][4] == 1 && arr[pos+1][0] == 0) {
            cout << 1;
            pos += 2;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 0 && arr[pos][2] == 1 && arr[pos][3] == 1 && arr[pos + 1][0] == 1) {
            cout << 2;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 0 && arr[pos][2] == 1 && arr[pos][3] == 0 && arr[pos][4] == 1) {
            cout << 3;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 1 && arr[pos][2] == 1 && arr[pos][3] == 0 && arr[pos][4] == 0) {
            cout << 4;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 1 && arr[pos][2] == 1 && arr[pos][3] == 0 && arr[pos][4] == 1 && arr[pos + 2][1] == 0) {
            cout << 5;
            pos += 4;
        }
        else if (arr[pos + 2][1] == 0 && arr[pos][3] == 1) {
            cout << 6;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 0 && arr[pos][2] == 0 && arr[pos][3] == 0 && arr[pos][4] == 0) {
            cout << 7;
            pos += 4;
        }
        else if (arr[pos][0] == 1 && arr[pos][1] == 1 && arr[pos][2] == 1 && arr[pos][3] == 1 && arr[pos][4] == 1) {
            cout << 8;
            pos += 4;
        }
        else if (arr[pos + 2][1] == 1 && arr[pos][3] == 0) {
            cout << 9;
            pos += 4;
        }
    }

    return 0;
}
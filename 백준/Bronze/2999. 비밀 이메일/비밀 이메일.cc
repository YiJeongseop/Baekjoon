#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int R, C;
    for (int i = sqrt(str.size()); i > 0; i--) {
        if (str.size() % i == 0 && i <= str.size() / i) {
            R = i; C = str.size() / R;
            break;
        }
    }

    //cout << R << ", " << C << '\n';

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << str[i + R * j];
        }
    }

    return 0;
}
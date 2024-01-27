#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool light[100];
string str;

void func(int start, int end) {
    //cout << "start : " << start << ", end : " << end << '\n';
    char target = 'Z' + 1;
    int idx = 0;
    for (int i = start; i <= end; i++) {
        if (str[i] < target && !light[i]) {
            idx = i;
            target = str[i];
        }
    }
    if (target == 'Z' + 1) {
        //cout << "target을 찾지 못했습니다. return" << '\n';
        return;
    }
    //cout << idx << "에 불이 켜집니다." << '\n';
    light[idx] = true;
    for (int i = 0; i < str.length(); i++) {
        if (light[i]) cout << str[i];
    }
    cout << '\n';

    func(idx + 1, end);
    func(start, idx - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    func(0, str.length() - 1);

    return 0;
}
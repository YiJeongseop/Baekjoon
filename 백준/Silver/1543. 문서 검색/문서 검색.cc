#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    int pos = 0, ans = 0;
    while (pos < a.size()) {
        int nxt_pos = a.find(b, pos);
        if (nxt_pos == -1) break;
        ans++;
        pos = nxt_pos + b.size();
    }
    cout << ans;

    return 0;
}
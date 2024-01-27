#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        int pos = 0;
        bool last = false;
        while (pos < str.size()) {
            if (!isdigit(str[pos])) {
                pos++;
                continue;
            }
            int nxt_pos = pos;
            while (isdigit(str[nxt_pos])) {
                if (nxt_pos + 1 == str.size()) {
                    last = true;
                    break;
                }
                nxt_pos++;
            }
            string tmp;
            if(!last) tmp = str.substr(pos, nxt_pos - pos);
            else if(last) tmp = str.substr(pos, nxt_pos - pos + 1);
            while (tmp[0] == '0') tmp.erase(0, 1);
            if (tmp.size() == 0) tmp = '0';
            v.push_back(tmp);
            if (!last) pos = nxt_pos;
            else if (last) pos = nxt_pos + 1;
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (string i : v) cout << i << '\n';

    return 0;
}
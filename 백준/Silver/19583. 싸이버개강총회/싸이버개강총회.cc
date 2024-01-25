#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int s_to_time(string str) {
    string tmp = str.substr(0, 2) + str.substr(3, 2);
    return stoi(tmp);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> m;

    string S, E, Q;
    cin >> S >> E >> Q;

    int S2 = s_to_time(S);
    int E2 = s_to_time(E);
    int Q2 = s_to_time(Q);

    int ans = 0;
    while (true) {
        string ti, name;
        cin >> ti >> name;
        if (cin.eof() == true) break;

        int ti2 = s_to_time(ti);
        if (ti2 <= S2) m[name] = ti2;
        else if (ti2 >= E2 && ti2 <= Q2) {
            if (m.find(name) != m.end()) {
                ans++;
                m.erase(name);
            }
        }
    }

    cout << ans;

    return 0;
}
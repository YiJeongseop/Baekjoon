#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split(string& s, string sep) {
    vector<string> ret;
    int pos = 0;
    while (pos < s.size()) {
        int nxt_pos = s.find(sep, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0) ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v, left, right;
    string IPv6;
    cin >> IPv6;

    if (IPv6 == "::") {
        cout << "0000:0000:0000:0000:0000:0000:0000:0000";
        return 0;
    }

    if (IPv6.find("::") != -1) {
        int pos = IPv6.find("::");
        if (pos == 0) {
            string tmp = IPv6.substr(2, IPv6.size() - 2);
            right = split(tmp, ":");
            for (int i = 0; i < 8 - right.size(); i++) {
                cout << "0000:";
            }
            for (int i = 0; i < right.size(); i++) {
                if (right[i].size() == 4) cout << right[i];
                else {
                    for (int j = 4; j > right[i].size(); j--) cout << "0";
                    cout << right[i];
                }
                if (i != right.size() - 1) cout << ":";
            }
        }
        else if (pos == IPv6.size() - 2) {
            string tmp = IPv6.substr(0, IPv6.size() - 2);
            left = split(tmp, ":");
            for (int i = 0; i < left.size(); i++) {
                if (left[i].size() == 4) cout << left[i] << ":";
                else {
                    for (int j = 4; j > left[i].size(); j--) cout << "0";
                    cout << left[i] << ":";
                }
            }
            for (int i = 0; i < 8 - left.size(); i++) {
                cout << "0000";
                if (i != 8 - left.size() - 1) cout << ":";
            }
        }
        else {
            string tmp = IPv6.substr(0, pos);
            left = split(tmp, ":");
            tmp = IPv6.substr(pos + 2, IPv6.size() - pos - 2);
            right = split(tmp, ":");
            for (int i = 0; i < left.size(); i++) {
                if (left[i].size() == 4) cout << left[i] << ":";
                else {
                    for (int j = 4; j > left[i].size(); j--) cout << "0";
                    cout << left[i] << ":";
                }
            }
            for (int i = 0; i < 8 - right.size() - left.size(); i++) {
                cout << "0000:";
            }
            for (int i = 0; i < right.size(); i++) {
                if (right[i].size() == 4) cout << right[i];
                else {
                    for (int j = 4; j > right[i].size(); j--) cout << "0";
                    cout << right[i];
                }
                if (i != right.size() - 1) cout << ":";
            }
        }
    }
    else {
        v = split(IPv6, ":");
        for (int i = 0; i < v.size(); i++) {
            if (v[i].size() == 4) cout << v[i];
            else {
                for (int j = 4; j > v[i].size(); j--) cout << "0";
                cout << v[i];
            }
            if (i != v.size() - 1) cout << ":";
        }
    }

    return 0;
}
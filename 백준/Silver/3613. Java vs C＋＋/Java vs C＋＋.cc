#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool is_c = false, is_java = false;

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') {
            is_c = true;
            if (i != 0 && str[i - 1] == '_') {
                cout << "Error!";
                return 0;
            }
        }
        else if (iswupper(str[i])) is_java = true;
    }

    if (iswupper(str[0]) || str[0] == '_' || str[str.size() - 1] == '_') {
        cout << "Error!";
        return 0;
    }

    if (is_c && is_java) cout << "Error!";
    else if (is_java) {
        for (int i = 1; i < str.size(); i++) {
            if (iswupper(str[i])) {
                string tmp2;
                char tmp = str[i] + 32;
                tmp2 += tmp;
                str.replace(i, 1, "_");
                str.insert(i + 1, tmp2);
            }
        }
        cout << str;
    }
    else {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '_') {
                string tmp2;
                char tmp = str[i + 1] - 32;
                tmp2 += tmp;
                str.replace(i, 2, tmp2);
            }
        }
        cout << str;
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string pattern, str;
    cin >> pattern;

    int star_pos = pattern.find('*');

    string target1 = pattern.substr(0, pattern.find('*'));
    string target2 = pattern.substr(pattern.find('*') + 1, pattern.size() - pattern.find('*') - 1);

    while (N--) {
        cin >> str;
        if (str.find(target1) != 0 || target1.size() + target2.size() > str.size()) {
            cout << "NE" << '\n';
            continue;
        }
        if (str.find(target2, str.size() - target2.size()) == -1) {
            cout << "NE" << '\n';
            continue;
        }
        cout << "DA" << '\n';
    }

    return 0;
}
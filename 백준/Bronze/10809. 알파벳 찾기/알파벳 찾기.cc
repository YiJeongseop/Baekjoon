#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	for (char alphabet = 'a'; alphabet < 'z' + 1; alphabet++) {
		if (s.find(alphabet) != string::npos) {
			cout << s.find(alphabet) << " ";
		}
		else {
			cout << -1 << " ";
		}
	}

	return 0;
}
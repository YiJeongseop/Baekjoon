#include <iostream>
#include <cstring>

using namespace std;

int Recursion(const char *s, int l, int r, int& cnt);

int IsPalindrome(const char* s, int& cnt);

int main()
{
	int n, cnt, result;
	cin >> n;
	char s[1001];

	for (int i = 0; i < n; i++) {
		cnt = 0;
		cin >> s;

		result = IsPalindrome(s, cnt);
		cout << result << " " << cnt << endl;
	}

	return 0;
}

int Recursion(const char *s, int l, int r, int& cnt) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return Recursion(s, l + 1, r - 1, cnt);
}

int IsPalindrome(const char* s, int& cnt) {
	return Recursion(s, 0, strlen(s) - 1, cnt);
}
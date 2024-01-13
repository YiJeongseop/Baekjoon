#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
long long arr[1000000];

bool cmp(const pair<long long, int>& a, const pair<long long, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        vector<char> v;
        for (int j = tmp.size() - 1; j >= 0; j--) {
            v.push_back(tmp[j]);
        }
        bool flag = true;
        string tmp2 = "";
        for (int j = 0; j < v.size(); j++) {
            if (v[j] != '0') {
                tmp2 += v[j];
                flag = false;
            }
            else if (v[j] == '0' && flag) continue; 
            else {
                tmp2 += v[j];
            }
        }

        long long ans = stoll(tmp2);
        arr[i] = ans;
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}
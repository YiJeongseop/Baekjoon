#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>

using namespace std;

int N;
tuple<string, int, int, int> arr[100000];

bool cmp(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b) {
    if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b))
        return get<0>(a) < get<0>(b);
    else if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
        return get<3>(a) > get<3>(b);
    else if (get<1>(a) == get<1>(b))
        return get<2>(a) < get<2>(b);
    else
        return get<1>(a) > get<1>(b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string name;
    int k, e, m;
    for (int i = 0; i < N; i++) {
        cin >> name >> k >> e >> m;
        arr[i] = { name, k, e, m };
    }

    sort(arr, arr + N, cmp);

    for (int i = 0; i < N; i++)
        cout << get<0>(arr[i]) << '\n';

    return 0;
}
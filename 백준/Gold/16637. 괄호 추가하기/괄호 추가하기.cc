#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

long long N, max_cnt, ans = INT_MIN;
vector<int> num;
vector<char> oper;
int mask[10];

long long cal(long long num1, char op, long long num2) {
    if (op == '+') {
        return num1 + num2;
    }
    else if (op == '-') {
        return num1 - num2;
    }
    else if (op == '*') {
        return num1 * num2;
    }
}

void func(int bracket_cnt) {
    int mask_size = N / 2;
    fill(mask, mask + mask_size, 0);
    for (int i = mask_size - 1; i > mask_size - 1 - bracket_cnt; i--) mask[i] = 1;

    do {
        bool flag = false;
        for (int i = 0; i < mask_size - 1; i++) {
            if (mask[i] == 1 && mask[i + 1] == 1) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        deque<long long> q;
        queue<char> q2;
        int num_cnt = 0;
        int oper_cnt = 0;
        for (int i = 0; i < mask_size; i++) {
            if (mask[i]) {
                q.push_back(cal(num[i], oper[i], num[i + 1]));
                num_cnt += 2;
                oper_cnt++;
            }
            else {
                if (i != 0 && mask[i - 1]) {
                    q2.push(oper[i]);
                    oper_cnt++;
                }
                else {
                    q.push_back(num[i]);
                    q2.push(oper[i]);
                    num_cnt++;
                    oper_cnt++;
                }
            }
        }
        if (num_cnt != num.size()) {
            for (int i = num_cnt; i < num.size(); i++)
                q.push_back(num[i]);
        }
        if (oper_cnt != oper.size()) {
            for (int i = oper_cnt; i < oper.size(); i++)
                q2.push(oper[i]);
        }

        while (!q.empty()) {
            long long temp1 = q.front();
            q.pop_front();
            char temp2 = q2.front();
            q2.pop();
            long long temp3 = q.front();
            q.pop_front();
            long long temp4 = cal(temp1, temp2, temp3);
            if (q.empty()) {
                ans = max(ans, temp4);
                break;
            }
            else {
                q.push_front(temp4);
            }
        }
    } while (next_permutation(mask, mask + mask_size));

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string temp;
    cin >> temp;

    if (N == 5) max_cnt = 1;
    else if (N == 7 || N == 9) max_cnt = 2;
    else if (N == 11 || N == 13) max_cnt = 3;
    else if (N == 15 || N == 17) max_cnt = 4;
    else if (N == 19) max_cnt = 5;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            num.push_back(temp[i] - '0');
        }
        else {
            oper.push_back(temp[i]);
        }
    }

    if (num.size() == 1) {
        cout << num[0];
        return 0;
    }
    else if (num.size() == 2) {
        cout << cal(num[0], oper[0], num[1]);
        return 0;
    }

    for (int i = 1; i <= max_cnt; i++) {
        func(i);
    }

    cout << ans;

    return 0;
}
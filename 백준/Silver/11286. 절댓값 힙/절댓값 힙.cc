#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> pq; // 최대힙
    priority_queue<int, vector<int>, greater<int>> pq2; // 최소힙

    int N; 
    cin >> N;
    while (N--) {
        int val; 
        cin >> val;
        if (val > 0) {
            pq2.push(val);
        }
        else if (val < 0) {
            pq.push(val);
        }
        else {
            if (pq.empty() && pq2.empty()) cout << 0 << '\n';
            else if (pq.empty()) {
                cout << pq2.top() << '\n';
                pq2.pop();
            }
            else if (pq2.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                if (-pq.top() > pq2.top()) {
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
                else if (-pq.top() < pq2.top()) {
                    cout << pq.top() << '\n';
                    pq.pop();
                }
                else {
                    cout << pq.top() << '\n';
                    pq.pop();
                }
            }
        }
    }

    return 0;
}
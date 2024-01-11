#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

int N, K, maxx = -1, minn = INT_MAX;
int fish_tank[101];
deque<int> dq[101];
vector<int> v[101];
vector<int> v2[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> fish_tank[i];
    }

    for (int i = 1; i <= N; i++) {
        maxx = max(maxx, fish_tank[i]);
        minn = min(minn, fish_tank[i]);
    }

    if (maxx - minn <= K) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while (true) {
        ans++;
        maxx = -1; minn = INT_MAX;

        for (int i = 1; i <= N; i++) {
            minn = min(minn, fish_tank[i]);
        }

        for (int i = 1; i <= N; i++) {
            if(fish_tank[i] == minn) fish_tank[i]++;
            dq[1].push_back(fish_tank[i]);
        }

        //cout << "덱 1층 : ";
        //for (int j = 0; j < dq[1].size(); j++) {
        //    cout << dq[1][j] << " ";
        //}
        //cout << '\n';
        //cout << '\n';

        int height = 1;
        int cnt = 0;
        while (dq[1].size() - dq[2].size() >= height) {
            if (cnt == 0) {
                int tmp2 = dq[1].front();
                dq[1].pop_front();
                dq[2].push_front(tmp2);
                height++;
            }
            else if (cnt == 1) {
                int tmp2 = dq[1].front();
                dq[1].pop_front();
                dq[2].push_front(tmp2);
            }
            else if (cnt % 2 == 0) {
                for (int i = 1; i <= height; i++) {
                    for (int j = 1; j <= height; j++) {
                        int tmp2 = dq[j].front();
                        dq[j].pop_front();
                        v[height + 2 - i].push_back(tmp2);
                    }
                }
                for (int i = height + 1; i > 1; i--) {
                    dq[i].clear();
                    for (int j = 0; j < v[i].size(); j++) {
                        dq[i].push_back(v[i][j]);
                    }
                    v[i].clear();
                }
                height++;
            }
            else {
                int width = dq[2].size();
                for (int i = 1; i <= width; i++) {
                    for (int j = 1; j <= height; j++) {
                        int tmp2 = dq[j].front();
                        dq[j].pop_front();
                        v[height + 1 - i].push_back(tmp2);
                    }
                }
                for (int i = height; i > 1; i--) {
                    dq[i].clear();
                    for (int j = 0; j < v[i].size(); j++) {
                        dq[i].push_back(v[i][j]);
                    }
                    v[i].clear();
                }
            }
            cnt++;
        }

        //for (int i = 1; i <= height; i++) {
        //    cout << "덱 " << i << "층 : ";
        //    for (int j = 0; j < dq[i].size(); j++) {
        //        cout << dq[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        int width1 = dq[1].size();
        int width2 = dq[2].size();
        for (int i = 1; i <= width1; i++) {
            int tmp2 = dq[1].front();
            dq[1].pop_front();
            v[1].push_back(tmp2);
            v2[1].push_back(tmp2);
        }
        for (int i = 2; i <= height; i++) {
            for (int j = 1; j <= width2; j++) {
                int tmp2 = dq[i].front();
                dq[i].pop_front();
                v[i].push_back(tmp2);
                v2[i].push_back(tmp2);
            }
        }

        //cout << "v2 1층:";
        //for (int i = 0; i < width1; i++) {
        //    cout << v2[1][i] << " ";
        //}
        //cout << '\n';
        //for (int i = 2; i <= height; i++) {
        //    cout << "v2 "<< i <<"층:";
        //    for (int j = 0; j < width2; j++) {
        //        cout << v2[i][j] << " ";
        //    }
        //    cout << '\n';
        //}

        for (int i = 0; i < width1 - 1; i++) {
            int tmp2 = abs(v[1][i] - v[1][i + 1]);
            int tmp3 = tmp2 / 5;
            if (tmp3 > 0) {
                if (v[1][i] > v[1][i + 1]) {
                    v2[1][i] -= tmp3;
                    v2[1][i + 1] += tmp3;
                }
                else {
                    v2[1][i] += tmp3;
                    v2[1][i + 1] -= tmp3;
                }
            }
        }
        for (int i = 2; i <= height; i++) {
            for (int j = 0; j < width2 - 1; j++) {
                int tmp2 = abs(v[i][j] - v[i][j + 1]);
                int tmp3 = tmp2 / 5;
                if (tmp3 > 0) {
                    if (v[i][j] > v[i][j + 1]) {
                        v2[i][j] -= tmp3;
                        v2[i][j + 1] += tmp3;
                    }
                    else {
                        v2[i][j] += tmp3;
                        v2[i][j + 1] -= tmp3;
                    }
                }
            }
        }
        for (int i = 1; i < height; i++) {
            for (int j = 0; j < width2; j++) {
                int tmp2 = abs(v[i][j] - v[i + 1][j]);
                int tmp3 = tmp2 / 5;
                if (tmp3 > 0) {
                    if (v[i][j] > v[i + 1][j]) {
                        v2[i][j] -= tmp3;
                        v2[i + 1][j] += tmp3;
                    }
                    else {
                        v2[i][j] += tmp3;
                        v2[i + 1][j] -= tmp3;
                    }
                }
            }
        }

        //cout << '\n';
        //cout << "v2 1층:";
        //for (int i = 0; i < width1; i++) {
        //    cout << v2[1][i] << " ";
        //}
        //cout << '\n';
        //for (int i = 2; i <= height; i++) {
        //    cout << "v2 " << i << "층:";
        //    for (int j = 0; j < width2; j++) {
        //        cout << v2[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        int idx = 1;
        for (int i = 0; i < width2; i++) {
            for (int j = 1; j <= height; j++) {
                fish_tank[idx++] = v2[j][i];
            }
        }
        for (int i = width2; i < width1; i++)
            fish_tank[idx++] = v2[1][i];

        //cout << "현재 어항 상태" << '\n';
        //for (int i = 1; i <= N; i++)
        //    cout << fish_tank[i] << " ";
        //cout << '\n';
        //cout << '\n';

        for (int i = 1; i <= height; i++) {
            v[i].clear();
            v2[i].clear();
        }

        for (int i = (N / 2); i > 0; i--)
            v[2].push_back(fish_tank[i]);
        for(int i = N / 2 + 1; i <= N; i++)
            v[1].push_back(fish_tank[i]);

        for (int i = (N / 4) - 1; i >= 0; i--) {
            v2[4].push_back(v[1][i]);
            v2[3].push_back(v[2][i]);
        }
        for (int i = N / 4; i < N / 2; i++) {
            v2[2].push_back(v[2][i]);
            v2[1].push_back(v[1][i]);
        }

        for (int i = 1; i <= 2; i++)
            v[i].clear();
        for (int i = 1; i <= 4; i++)
            v[i] = v2[i];

        //cout << "현재 v2 상태" << '\n';
        //for (int i = 1; i <= 4; i++) {
        //    cout << i << "층 : ";
        //    for (int j = 0; j < N / 4; j++) {
        //        cout << v2[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < v2[1].size() - 1; j++) {
                int tmp2 = abs(v2[i][j] - v2[i][j + 1]);
                int tmp3 = tmp2 / 5;
                if (tmp3 > 0) {
                    if (v2[i][j] > v2[i][j + 1]) {
                        v[i][j] -= tmp3;
                        v[i][j + 1] += tmp3;
                    }
                    else {
                        v[i][j] += tmp3;
                        v[i][j + 1] -= tmp3;
                    }
                }
            }
        }
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j < v2[1].size(); j++) {
                int tmp2 = abs(v2[i][j] - v2[i + 1][j]);
                int tmp3 = tmp2 / 5;
                if (tmp3 > 0) {
                    if (v2[i][j] > v2[i + 1][j]) {
                        v[i][j] -= tmp3;
                        v[i + 1][j] += tmp3;
                    }
                    else {
                        v[i][j] += tmp3;
                        v[i + 1][j] -= tmp3;
                    }
                }
            }
        }

        //cout << "현재 v 상태" << '\n';
        //for (int i = 1; i <= 4; i++) {
        //    cout << i << "층 : ";
        //    for (int j = 0; j < N / 4; j++) {
        //        cout << v[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        int idx2 = 1;
        for (int i = 0; i < v[1].size(); i++) {
            for (int j = 1; j <= 4; j++) {
                fish_tank[idx2++] = v[j][i];
            }
        }

        //cout << "현재 어항 상태" << '\n';
        //for (int i = 1; i <= N; i++)
        //    cout << fish_tank[i] << " ";
        //cout << '\n';
        //cout << '\n';

        for (int i = 1; i <= 4; i++) {
            v[i].clear();
            v2[i].clear();
        }

        maxx = -1; minn = INT_MAX;

        for (int i = 1; i <= N; i++) {
            maxx = max(maxx, fish_tank[i]);
            minn = min(minn, fish_tank[i]);
        }

        if (maxx - minn <= K) {
            cout << ans;
            return 0;
        }
    }

    return 0;
}
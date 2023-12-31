#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int alphabet[26];
char board[100][100];
int visited[100][100];
int T, h, w;
string keys;

int BFS(int y, int x) {
    int count = 0;
    queue<pair<int, int>> q;
    if (board[y][x] == '$') {
        count++;
        board[y][x] = '.';
    }
    else if (board[y][x] >= 'a' && board[y][x] <= 'z') {
        alphabet[board[y][x] - 'a'] = 1;
        board[y][x] = '.';
    }
    else if (board[y][x] >= 'A' && board[y][x] <= 'Z') {
        if (alphabet[board[y][x] - 'A']) {
            board[y][x] = '.';
        }
        else {
            return 0;
        }
    }
    q.push({ y, x });
    visited[y][x] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if (ny < 0 || nx < 0 || nx >= w || ny >= h) continue;

            /*cout << '\n';
            cout << "ny : " << ny << ", nx : " << nx << '\n';
            cout << "visited[ny][nx] : " << visited[ny][nx] << '\n';
            cout << "board[ny][nx] : " << board[ny][nx] << '\n';
            cout << '\n';*/

            if (visited[ny][nx] || board[ny][nx] == '*') continue;
            if (board[ny][nx] >= 'A' && board[ny][nx] <= 'Z') {
                if (alphabet[board[ny][nx] - 'A']) {
                    visited[ny][nx] = true;
                    //cout << "문을 열겠습니다. 알파벳은 " << board[ny][nx] << "입니다. " << '\n';
                    //cout << "큐에 " << ny << ", " << nx << " 가 들어갑니다. " << '\n';
                    q.push({ ny, nx });
                    board[ny][nx] = '.';
                    continue;
                }
                else continue;
            }
            if (board[ny][nx] >= 'a' && board[ny][nx] <= 'z') {
                for (int i = 0; i < h; i++)
                    fill(visited[i], visited[i] + w, 0);
                while (!q.empty()) q.pop();
                visited[ny][nx] = true;
                //cout << "열쇠를 습득했습니다. 알파벳은 " << board[ny][nx] << "입니다. " << '\n';
                //cout << "큐에 " << ny << ", " << nx << " 가 들어갑니다. " << '\n';
                q.push({ ny, nx });
                alphabet[board[ny][nx] - 'a'] = 1;
                board[ny][nx] = '.';
                break;
            }
            if (board[ny][nx] == '$') {
                count++;
                board[ny][nx] = '.';
            }
            visited[ny][nx] = true;
            //cout << "큐에 " << ny << ", " << nx << " 가 들어갑니다. " << '\n';
            q.push({ ny, nx });
        }
    }
    return count;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        int answer = 0;
        fill(alphabet, alphabet + 26, 0);

        cin >> h >> w;
        for (int y = 0; y < h; y++) {
            fill(visited[y], visited[y] + w, 0);
            for (int x = 0; x < w; x++) {
                cin >> board[y][x];
            }
        }

        cin >> keys;
        if (keys != "0") {
            for (int i = 0; i < keys.length(); i++) {
                alphabet[keys[i] - 'a'] = 1;
            }
        }
        
        int temp = 0;
        while (true) {
            temp = answer;
            for (int y : {0, h - 1}) {
                for (int x = 0; x < w; x++) {
                    if (board[y][x] != '*') {
                        answer += BFS(y, x);
                    }
                }
            }

            for (int x : {0, w - 1}) {
                for (int y = 1; y < h - 1; y++) {
                    if (board[y][x] != '*') {
                        answer += BFS(y, x);
                    }
                }
            }
            if (answer == temp) break;
        }

        cout << answer << '\n';
    }

    return 0;
}
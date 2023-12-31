#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[1001][1001];
int arr[1001][1001][11];
int N, M, K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    string temp;
    for (int y = 1; y <= N; y++) {
        cin >> temp;
        for (int x = 1; x <= M; x++) {
            if (temp[x - 1] == '0') board[y][x] = 0;
            else board[y][x] = -1;
        }
    }

    arr[1][1][K] = 1;
    queue<tuple<int, int, int, int>> q;
    q.push({ 1, 1, K, 1 });
    while (!q.empty()) {
        int y, x, broken, day, next_day;
        tie(y, x, broken, day) = q.front();

        //cout << '\n';
        //cout << '\n';
        //cout << "현재 y, x, broken, day : " << y << "  " << x << "  " << broken << "  " << day << '\n';
        //cout << "현재 broken은 " << broken << "입니다. " << '\n';
        //for (int i = 1; i <= 3; i++) {
        //    for (int j = 1; j <= 3; j++) {
        //        cout << arr[i][j][broken] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
        //cout << '\n';

        if (day == 1) next_day = 0;
        else next_day = 1;

        if (y == N && x == M) {
            cout << arr[y][x][broken];
            return 0;
        }

        q.pop();
        
        int temp = arr[y][x][broken];
        bool flag = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx <= 0 || nx > M || ny <= 0 || ny > N) continue;
            if (arr[ny][nx][broken] > 0) continue;
            if (broken != 10 && arr[ny][nx][broken + 1] > 0) continue;
            if (broken > 0 && board[ny][nx] == -1 && !arr[ny][nx][broken - 1]) {
                if (day == 0 && flag) {
                    //cout << y << ", " << x << ", " << broken << "앞에서부터 y, x, broken의 arr 값이 1 더해졌습니다." << '\n'; 
                    arr[y][x][broken]++;
                    flag = false;
                    //cout << "더해진 결과 : " << arr[y][x][broken] << '\n';
                    //cout << y << ", " << x << ", " << broken << "을 큐에 넣었습니다." << '\n';
                    q.push({ y, x, broken, next_day });
                }
                else if (day == 1){
                    arr[ny][nx][broken - 1] = temp + 1;
                    //cout << ny << ", " << nx << ", " << broken - 1 << "을 큐에 넣었습니다." << '\n';
                    //cout << "위 좌표의 arr 값은 " << temp + 1 << "이 되었습니다. " << '\n';
                    q.push({ ny, nx, broken - 1, next_day });
                }
            }
            if (board[ny][nx] == -1) continue;
            arr[ny][nx][broken] = temp + 1;
            //cout << ny << ", " << nx << ", " << broken << "을 큐에 넣었습니다." << '\n';
            //cout << "위 좌표의 arr 값은 " << temp + 1 << "이 되었습니다. " << '\n';
            q.push({ ny, nx, broken, next_day});
        }
    }

    cout << -1;

    return 0;
}
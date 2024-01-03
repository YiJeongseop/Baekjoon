#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M, x, y, K, command, top = 1;
int map[20][20];
int dice[7];
int state[7] = { 0, 1, 3, 2, 4, 5, 6 }; // X 위 동 북 서 남 밑
int temp[7];

void change_state(int dir) {
    for (int i = 1; i < 7; i++) {
        temp[i] = state[i];
    }
    switch (dir) {
    case 1: // 동
        state[6] = temp[2];
        state[2] = temp[1];
        state[1] = temp[4];
        state[4] = temp[6];
        break;
    case 2: // 서
        state[6] = temp[4];
        state[4] = temp[1];
        state[1] = temp[2];
        state[2] = temp[6];
        break;
    case 3: // 북
        state[6] = temp[3];
        state[3] = temp[1];
        state[1] = temp[5];
        state[5] = temp[6];
        break;
    case 4: // 남
        state[6] = temp[5];
        state[5] = temp[1];
        state[1] = temp[3];
        state[3] = temp[6];
        break;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> map[x][y];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> command;
        int nx = x + dx[command - 1];
        int ny = y + dy[command - 1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        //cout << "y : " << ny << ", x : " << nx << "로 이동합니다. " << '\n';
        change_state(command);
        if (map[nx][ny] == 0) {
            //cout << "맵에 적혀있는 숫자가 0입니다. " << dice[state[6]] << "을 맵에 대입합니다." << '\n';
            map[nx][ny] = dice[state[6]];
        }
        else {
            //cout << "맵에 적혀있는 숫자가 "<< map[ny][nx] << "입니다. 주사위 밑에 대입합니다." << '\n';
            dice[state[6]] = map[nx][ny];
            map[nx][ny] = 0;
        }
        //cout << "현재 주사위의 상태 - 위 : " << dice[state[1]] << ", 동 : " << dice[state[2]] << ", 북 : " << dice[state[3]] << ", 서 : " << dice[state[4]] << ", 남 : " << dice[state[5]] << ", 밑 : " << dice[state[6]] << '\n';
        cout << dice[state[1]] << '\n';
        x = nx;
        y = ny;
    }

    return 0;
}
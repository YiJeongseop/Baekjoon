#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

int dx[6] = { 1, 0, -1, 0, 0, 0};
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int board[5][4][5][5];
int cube[5][5][5];
//int real_cube[5][5][5];
int visited[5][5][5];
queue<tuple<int, int, int, int>> maze;

void rotate(int i) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            board[i][1][x][4 - y] = board[i][0][y][x];
        }
    }
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            board[i][2][x][4 - y] = board[i][1][y][x];
        }
    }
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            board[i][3][x][4 - y] = board[i][2][y][x];
        }
    }
}

void visited_reset() {
    for (int z = 0; z < 5; z++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                visited[z][y][x] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                cin >> board[i][0][y][x];
            }
        }
        rotate(i);
    }

    int order[5] = { 0, 1, 2, 3, 4 };

    //vector<pair<int, int>> start_pos = { {0, 0}, {0, 4}, {4, 0}, {4, 4} };
    //vector<pair<int, int>> end_pos = { {4, 4}, {4, 0}, {0, 4}, {0, 0} };

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        //copy(&board[0][i][0][0], &board[0][i][0][0] + 25, &cube[0][0][0]);
        for (int j = 0; j < 4; j++) {
            //copy(&board[1][j][0][0], &board[1][j][0][0] + 25, &cube[1][0][0]);
            for (int k = 0; k < 4; k++) {
                //copy(&board[2][k][0][0], &board[2][k][0][0] + 25, &cube[2][0][0]);
                for (int l = 0; l < 4; l++) {
                    //copy(&board[3][l][0][0], &board[3][l][0][0] + 25, &cube[3][0][0]);
                    for (int n = 0; n < 4; n++) {
                        //copy(&board[4][n][0][0], &board[4][n][0][0] + 25, &cube[4][0][0]);
                        do {
                            copy(&board[0][i][0][0], &board[0][i][0][0] + 25, &cube[order[0]][0][0]);
                            copy(&board[1][j][0][0], &board[1][j][0][0] + 25, &cube[order[1]][0][0]);
                            copy(&board[2][k][0][0], &board[2][k][0][0] + 25, &cube[order[2]][0][0]);
                            copy(&board[3][l][0][0], &board[3][l][0][0] + 25, &cube[order[3]][0][0]);
                            copy(&board[4][n][0][0], &board[4][n][0][0] + 25, &cube[order[4]][0][0]);
                            /*copy(&cube[order[0]][0][0], &cube[order[0]][0][0] + 25, &real_cube[0][0][0]);
                            copy(&cube[order[1]][0][0], &cube[order[1]][0][0] + 25, &real_cube[1][0][0]);
                            copy(&cube[order[2]][0][0], &cube[order[2]][0][0] + 25, &real_cube[2][0][0]);
                            copy(&cube[order[3]][0][0], &cube[order[3]][0][0] + 25, &real_cube[3][0][0]);
                            copy(&cube[order[4]][0][0], &cube[order[4]][0][0] + 25, &real_cube[4][0][0]);*/

                            for (int pos_index = 0; pos_index < 4; pos_index++) {
                                //int s_pos_y, s_pos_x, e_pos_y, e_pos_x;
                                //tie(s_pos_y, s_pos_x) = start_pos[pos_index];
                                //tie(e_pos_y, e_pos_x) = end_pos[pos_index];
                                if (cube[0][0][0] == 0 || cube[4][4][4] == 0) {
                                    continue;
                                }
                                visited_reset();
                                maze.push({ 0, 0, 0, 0 });
                                visited[0][0][0] = true;
                                while (!maze.empty()) {
                                    int maze_z, maze_y, maze_x, count_;
                                    tie(maze_z, maze_y, maze_x, count_) = maze.front();
                                    maze.pop();
                                    if (maze_z == 4 && maze_y == 4 && maze_x == 4) {
                                        ans = min(ans, count_);
                                        break;
                                    }
                                    for (int dir = 0; dir < 6; dir++) {
                                        int nx = maze_x + dx[dir];
                                        int ny = maze_y + dy[dir];
                                        int nz = maze_z + dz[dir];
                                        if (nx < 0 || ny < 0 || nz < 0 || nz > 4 || nx > 4 || ny > 4) continue;
                                        if (visited[nz][ny][nx] || cube[nz][ny][nx] == 0) continue;
                                        visited[nz][ny][nx] = true;
                                        maze.push({ nz, ny, nx, count_ + 1 });
                                    }
                                }
                                while (!maze.empty()) maze.pop();
                            }
                        } while (next_permutation(order, order + 5));
                    }
                }
            }
        }
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}
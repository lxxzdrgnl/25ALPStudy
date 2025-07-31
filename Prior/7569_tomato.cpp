#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tuple<int, int, int>> q;
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == 1) {
                    q.push({z, y, x});
                }
            }
        }
    }

    int day = 0;

    while (!q.empty()) {
        int size = q.size();
        bool ripe = false;

        for (int i = 0; i < size; i++) {
            // 3차원 좌표를 위한 tuple -> get,  make_tuple
            tuple<int, int, int> current = q.front();
            q.pop();
            int z = get<0>(current);
            int y = get<1>(current);
            int x = get<2>(current);

            for (int j = 0; j < 6; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];

                if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    ripe = true;
                    q.push(make_tuple(nz, ny, nx));
                }
            }
        }
        if (ripe) day++;
    }

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 0) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << day;
}
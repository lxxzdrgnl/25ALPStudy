#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (t--) {
        int w, h;
        cin >> w >> h;

        vector<string> building(h);
        vector<vector<int>> fire_time(h, vector<int>(w, -1));
        vector<vector<int>> person_time(h, vector<int>(w, -1));
        queue<pair<int, int>> fire, person;

        // 초기 불, 사람 위치 0
        for (int i = 0; i < h; i++) {
            cin >> building[i];
            for (int j = 0; j < w; j++) {
                if (building[i][j] == '@') {
                    person.push({i, j});
                    person_time[i][j] = 0;
                }
                if (building[i][j] == '*') {
                    fire.push({i, j});
                    fire_time[i][j] = 0;
                }
            }
        }

        // 불 BFS 실행
        while (!fire.empty()) {
            pair<int, int> p = fire.front();
            int x = p.first, y = p.second;

            fire.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (building[nx][ny] == '#' || fire_time[nx][ny] != -1) continue;
                fire_time[nx][ny] = fire_time[x][y] + 1;
                fire.push({nx, ny});
            }
        }

        // 상근이 BFS 실행
        bool escaped = false;
        while (!person.empty() && !escaped) {
            pair<int, int> p = person.front();
            person.pop();
            int x = p.first, y = p.second;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    cout << person_time[x][y] + 1 << "\n";
                    escaped = true;
                    break;
                }

                if (building[nx][ny] == '#' || person_time[nx][ny] != -1) continue;
                if (fire_time[nx][ny] != -1 && person_time[x][y] + 1 >= fire_time[nx][ny]) continue;

                person_time[nx][ny] = person_time[x][y] + 1;
                person.push({nx, ny});
            }
        }

        if (!escaped) cout << "IMPOSSIBLE\n";
    }
}

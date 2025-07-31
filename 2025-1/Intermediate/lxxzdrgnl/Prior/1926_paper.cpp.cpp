#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0, max_area = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};  // 상하좌우 이동

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                count++;  // 새로운 그림 발견
                int area = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    area++;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && graph[nx][ny] == 1) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                max_area = max(max_area, area);
            }
        }
    }

    cout << count << "\n"
         << max_area;
}
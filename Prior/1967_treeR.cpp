#include <bits/stdc++.h>

#include <iostream>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0, farthestNode = 0;

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }

    for (const auto& edge : tree[node]) {
        if (!visited[edge.first]) {               // 첫 번째 노드
            dfs(edge.first, dist + edge.second);  // 두 번째  가중치
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    dfs(1, 0);
    fill(begin(visited), end(visited), false);  // 방문 배열 초기화

    dfs(farthestNode, 0);  // 가장 먼 노드에서 DFS

    cout << maxDist << endl;
}
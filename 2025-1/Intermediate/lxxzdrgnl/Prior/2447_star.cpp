#include <bits/stdc++.h>

#include <iostream>

using namespace std;

void pattern(vector<vector<char>> &board, int x, int y, int n) {
    if (n == 1) {
        board[x][y] = '*';
        return;
    }

    int newSize = n / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;  // 가운데 부분 공백
            }
            pattern(board, x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, ' '));

    pattern(board, 0, 0, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
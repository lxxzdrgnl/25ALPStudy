#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int n, m;
int inputArr[8], selectedArr[8];
bool visited[8] = {false};

void backtrack(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << selectedArr[i] << " ";
        cout << "\n";
        return;
    }
    int prevNum = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && inputArr[i] != prevNum) {
            selectedArr[depth] = inputArr[i];
            prevNum = selectedArr[depth];
            visited[i] = true;
            backtrack(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> inputArr[i];

    sort(inputArr, inputArr + n);
    backtrack(0);
}

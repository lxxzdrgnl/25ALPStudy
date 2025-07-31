#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int L, C;
vector<char> chars;
vector<char> password;

void backtrack(int depth, int ja, int mo) {
    if (password.size() == L) {
        if (ja >= 1 && mo >= 2) {
            for (char c : password) cout << c;
            cout << "\n";
        }
        return;
    }
    for (int i = depth; i < C; i++) {
        password.push_back(chars[i]);
        if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') {
            backtrack(i + 1, ja + 1, mo);
        } else {
            backtrack(i + 1, ja, mo + 1);
        }
        password.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    chars.resize(C);

    for (int i = 0; i < C; i++) cin >> chars[i];

    sort(chars.begin(), chars.end());
    backtrack(0, 0, 0);
}

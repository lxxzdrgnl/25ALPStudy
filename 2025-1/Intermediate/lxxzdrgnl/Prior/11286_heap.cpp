#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (q.empty()) {
                cout << 0 << endl;
            } else {
                cout << q.top().second << endl;
                q.pop();
            }
        } else {
            q.push({abs(x), x});
        }
    }
}
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    stack<pair<int, int> > s;  // index, height
    int n, height;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> height;
 
        while (!s.empty()) {
            if (height < s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            //수신탑 찾을 때까지 계속 pop
            s.pop();
        }
        if (s.empty()) {
            cout << 0 << " ";
        }
        //현재 높이를 스택에 푸쉬
        s.push(make_pair(i + 1, height));
    }
     
    return 0;
}
#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string p, arr;
        int size;
        cin >> p >> size >> arr;

        deque<int> dq;
        bool rev = false, error = false;

        // 숫자 읽기
        string num = "";
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;               // 숫자면 문자열에 추가
            } else if (!num.empty()) {  // 숫자가 끝났으면 deque에 추가
                dq.push_back(stoi(num));
                num = "";
            }
        }

        // 명령 수행
        for (char cmd : p) {
            if (cmd == 'R') {
                rev = !rev;
            } else {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                rev ? dq.pop_back() : dq.pop_front();
            }
        }

        // 결과 출력
        if (error) {
            cout << "error\n";
        } else {
            cout << "[";
            while (!dq.empty()) {
                cout << (rev ? dq.back() : dq.front());
                rev ? dq.pop_back() : dq.pop_front();
                if (!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
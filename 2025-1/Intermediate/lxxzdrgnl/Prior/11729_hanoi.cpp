#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int by) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi(n - 1, from, by, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, by, to, from);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";  // 최소 이동 횟수: 2^N - 1
    hanoi(n, 1, 3, 2);
    return 0;
}
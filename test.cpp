#include <iostream>
using namespace std;

class point {
   private:
    int x, y;

   public:
    int getX() {
        return x;
    }
    int getY() {
        return x;
    }

    void addPoint(point &b) {
        x += b.getX();
        y += b.getX();
    }

    void setXY() {
        cin >> x >> y;
    }

    void printXY() {
        cout << "x : " << x << " y : " << y << endl;
    }
};

int main() {
    point a1;
    point a2;
    a1.setXY();
    a2.setXY();
    cout << "a1 position = ";
    a1.printXY();
    cout << "a2 position = ";
    a2.printXY();
    cout << "add result = ";
    a1.addPoint(a2);
    a1.printXY();
}
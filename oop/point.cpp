#include <assert.h>

class Point {
public:
  int x;
  int y;
  Point(int newX, int newY) : x(newX), y(newY) {}
  Point operator+(Point &p2) {
    Point p1(0, 0);
    p1.x = x + p2.x;
    p1.y = y + p2.y;
    return p1;
  }
};

int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2;
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}
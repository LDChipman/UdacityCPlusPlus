#include <assert.h>
#include <cmath>
#include <iostream>

const float pi = std::acos(0.0) * 2;

class LineSegment {
public:
  void SetLength(float newLength) { length = newLength; }
  float GetLength() { return length; }

protected:
  float length;
};

class Circle {
public:
  void SetRadius(float newRadius) {
    if (newRadius >= 1)
      radius.SetLength(newRadius);
  }
  float GetArea() { return pi * std::pow(radius.GetLength(), 2); }

private:
  LineSegment radius;
};

int main() {
  Circle circle;
  circle.SetRadius(3);
  assert(int(circle.GetArea()) == 28);
}
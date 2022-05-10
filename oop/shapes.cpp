#include <assert.h>
#include <cmath>

double pi = std::acos(0.0) * 2;

class Shape {
public:
  virtual float Area() const = 0;
  virtual float Perimeter() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(int newHeight, int newWidth) {
    height = newHeight;
    width = newWidth;
  }

  float Area() const override { return height * width; }
  float Perimeter() const override { return (height + width) * 2; }

private:
  int height;
  int width;
};

class Circle : public Shape {
private:
  float radius_;

public:
  Circle(float radius) { radius_ = radius; }

  float Area() const override { return pi * std::pow(radius_, 2); }
  float Perimeter() const override { return pi * 2 * radius_; }
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}
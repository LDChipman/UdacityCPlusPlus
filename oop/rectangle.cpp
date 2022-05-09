#include <assert.h>

class Square {
private:
  friend class Rectangle;
  int side_;

public:
  Square(int side) : side_(side) {}
};

class Rectangle {
private:
  int width_;
  int height_;

public:
  Rectangle(Square square) : width_(square.side_), height_(square.side_) {}
  int GetArea() const { return width_ * height_; }
};

int main() {
  Square square(4);
  Rectangle rectangle(square);
  assert(rectangle.GetArea() == 16);
}
#include <cassert>
#include <stdexcept>

class Pyramid {
private:
  int length_;
  int width_;
  int height_;

public:
  Pyramid(int length, int width, int height) {
    SetLength(length);
    SetWidth(width);
    SetHeight(height);
  }

  int GetLength() const { return length_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }

  void SetLength(int newLength) {
    if (newLength >= 1)
      length_ = newLength;
    else
      throw std::invalid_argument(
          "Cannot set length to an integer less than 1");
  }

  void SetWidth(int newWidth) {
    if (newWidth >= 1)
      width_ = newWidth;
    else
      throw std::invalid_argument("Cannot set width to an integer less than 1");
  }

  void SetHeight(int newHeight) {
    if (newHeight >= 1)
      height_ = newHeight;
    else
      throw std::invalid_argument(
          "Cannot set height to an integer less than 1");
  }

  int GetVolume() { return length_ * width_ * height_ / 3; }
};

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.GetLength() == 4);
  assert(pyramid.GetWidth() == 5);
  assert(pyramid.GetHeight() == 6);
  assert(pyramid.GetVolume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
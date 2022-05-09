#include <cassert>
#include <cmath>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
public:
  Sphere(int radius) : radius_(radius) {}
  int GetRadius() const { return radius_; }
  void SetRadius(int radius) {
    if (radius >= 1) {
      radius_ = radius;
    }
  }
  float GetVolume() const {
    return (std::acos(0.0) * 2) *
           (1.3333333333333 * (radius_ * radius_ * radius_));
  }

private:
  int radius_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.GetRadius() == 5);
  assert(abs(sphere.GetVolume() - 523.6) < 1);
}
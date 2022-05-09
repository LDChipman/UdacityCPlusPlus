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
  static float GetVolume(int radius) {
    return (std::acos(0.0) * 2) *
           (1.3333333333333 * (radius * radius * radius));
  }

private:
  int radius_;
};

// Test
int main(void) { assert(abs(Sphere::GetVolume(5) - 523.6) < 1); }
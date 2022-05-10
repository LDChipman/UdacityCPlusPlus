#include <assert.h>
#include <cmath>

double PI = std::acos(0.0) / 2;

class VehicleModel {
public:
  virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public VehicleModel {
public:
  void Move(double v, double phi) override {
    theta += phi;
    x += v * std::cos(theta);
    y += v * std::cos(theta);
  }
  double x;
  double y;
  double theta;
};

class BicycleModel : public ParticleModel {
public:
  void Move(double v, double phi) override {
    theta += v / L * std::tan(phi);
    x += v * std::cos(theta);
    y += v * std::cos(theta);
  }
  double L;
};

int main() {
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}
#include <cassert>

class Vehicle {
public:
  int seats;
};

class Car : public Vehicle {
public:
  int wheels;
};

class Sedan : public Car {
public:
  Sedan() {
    seats = 4;
    wheels = 4;
    trunk = true;
  }
  bool trunk;
};
int main() {
  Sedan sedan;
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}
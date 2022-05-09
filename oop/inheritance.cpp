#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
  int wheels = 0;
  string color = "blue";
  int cost = 0;

  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels
              << " wheels, and is worth " << cost << " dollars!\n";
  }
};

class Car : public Vehicle {
public:
  bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
  bool kickstand = true;
};

class GiantSpiderMount : public Vehicle {
public:
  std::string hungerLevel = "Sated";
};

int main() {
  Car car;
  car.wheels = 4;
  car.sunroof = true;
  car.cost = -7;
  car.Print();
  if (car.sunroof)
    std::cout << "And has a sunroof!\n";
  GiantSpiderMount spooder;
  spooder.color = "brown";
  spooder.cost = 100000;
  spooder.hungerLevel = "Very Hungry";
  spooder.Print();
  std::cout << "And it is " << spooder.hungerLevel << ".\n";
};
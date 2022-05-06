#include <cstring>
#include <iostream>
#include <string>

class Car {
private:
  int horsepower;
  int weight;
  char *brand;

public:
  Car(int horsepower, int weight, std::string brand);
  int GetHorsepower() const;
  int GetWeight() const;
  std::string GetBrand() const;
  void SetHorsepower(int newHorsepower);
  void SetWeight(int newWeight);
  void SetBrand(std::string newBrand);
};

Car::Car(int horsepower, int weight, std::string brand)
    : horsepower(horsepower), weight(weight) {
  SetBrand(brand);
}

int Car::GetHorsepower() const { return horsepower; }
int Car::GetWeight() const { return weight; }
std::string Car::GetBrand() const {
  std::string brandString = "";

  return brandString += brand;
}
void Car::SetHorsepower(int newHorsepower) { horsepower = newHorsepower; }
void Car::SetWeight(int newWeight) { weight = newWeight; }
void Car::SetBrand(std::string newBrand) {
  brand = new char[newBrand.length() + 1];
  strcpy(brand, newBrand.c_str());
}

// Test in main()
int main() {
  Car car(0, 0, "Hello");
  car.SetBrand("Peugeot");
  std::cout << car.GetBrand() << "\n";
}
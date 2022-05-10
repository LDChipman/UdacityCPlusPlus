#include <assert.h>
#include <iostream>
#include <string>

class Animal {
public:
  double age;
};

class Pet {
public:
  std::string name;
};

class Dog : public Animal, public Pet {
public:
  std::string breed;
};

class Cat : public Animal, public Pet {
public:
  std::string color;
};

int main() {
  Cat cat;
  cat.color = "black";
  cat.name = "Max";
  cat.age = 10;
  assert(cat.color == "black");
  assert(cat.age == 10);
  assert(cat.name == "Max");
}
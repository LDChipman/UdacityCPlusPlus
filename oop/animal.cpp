#include <iostream>
#include <string>

class Animal {
public:
  std::string color;
  std::string name;
  int age;
};

class Snake : public Animal {
public:
  float length;
  void MakeSound() { std::cout << "I'm a scary snekky snek!\n"; }
};

class Cat : public Animal {
public:
  float height;
  void MakeSound() { std::cout << "Meow.\n"; }
};

int main() {
  Cat cat;
  cat.color = "Gray";
  cat.name = "Bunny";
  cat.age = 7;
  cat.height = 35;
  cat.MakeSound();

  Snake snake;
  snake.color = "Red and white";
  snake.name = "Stripes";
  snake.age = 0;
  snake.length = 0;
  snake.MakeSound();
}
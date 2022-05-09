#include <iostream>
#include <string>

void hello() { std::cout << "Hello, World!\n"; }

class Human {};

void hello(Human human) { std::cout << "Hello, Human!\n"; }

class Dirt {};

void hello(Dirt dirt) { std::cout << "Hello, Dirt!\n"; }

class Air {};

void hello(Air air) { std::cout << "Hello, Air!\n"; }

int main() {
  hello();
  Human human;
  hello(human);
  Dirt dirt;
  hello(dirt);
  Air air;
  hello(air);
}
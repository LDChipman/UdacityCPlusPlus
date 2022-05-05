#include <assert.h>
#include <string>

class Person {
public:
  std::string name;
  Person(std::string newName) : name(newName) {}
};

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}
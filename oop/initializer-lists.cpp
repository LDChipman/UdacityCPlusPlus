#include <assert.h>
#include <string>

struct Person {
public:
  Person(std::string name) : name(name) {}
  std::string const name;
};

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}
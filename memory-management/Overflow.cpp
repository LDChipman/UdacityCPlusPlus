#include <iostream>

void RecursiveVariable(int &calls) {
  calls++;
  int variable = 1;
  std::cout << "Calls: " << calls << "\nBottom: " << &calls
            << "\nCurrent: " << &variable << "\n";
  RecursiveVariable(calls);
}

int main() {
  int calls = 0;
  RecursiveVariable(calls);
}
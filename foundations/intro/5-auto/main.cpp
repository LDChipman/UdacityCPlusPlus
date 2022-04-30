#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  auto v = {7, 8, 9, 10};
  for (int i : v) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
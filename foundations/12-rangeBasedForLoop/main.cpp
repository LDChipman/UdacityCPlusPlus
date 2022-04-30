#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> v = {0, 1, 0, 0, 0, 0};
  for (int i : v) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
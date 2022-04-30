#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> v = {6, 7, 8};

  for (int i : v) {
    cout << i << " ";
  }

  cout << "\n";

  return 0;
}
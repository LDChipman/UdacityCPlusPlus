#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int additionFunction(vector<int> v) {
  int sum = 0;
  for (int i : v) {
    sum += i;
  }

  return sum;
}

int main() {
  vector<int> v = {1, 2, 3};
  cout << additionFunction(v) << "\n";
  return 0;
}
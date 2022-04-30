#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<vector<int>> b = {{1, 2}, {3, 4}, {5, 6}};
  for (vector<int> v : b) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
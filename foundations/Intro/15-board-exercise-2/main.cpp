#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0}};
  for (vector<int> v : board) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
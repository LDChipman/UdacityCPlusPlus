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
  cout << board[0][1] << "\n";
  return 0;
}
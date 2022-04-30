#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::fstream;
using std::string;

int ReadBoardFile(string filepath) {
  fstream board(filepath);
  string line;
  if (board) {
    while (getline(board, line)) {
      cout << line << "\n";
    }
    return 0;
  } else {
    cout << "Failed to read file from given filepath.\n";
    return -1;
  }
}

int main() { return ReadBoardFile("./1.board"); }
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::fstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line) {
  vector<int> boardLine;
  istringstream boardStream(line);
  char c;
  int n;
  while (boardStream >> n >> c) {
    boardLine.push_back(n);
  }
  return boardLine;
}

vector<vector<int>> ReadBoardFile(string filepath) {
  fstream board(filepath);
  string line;
  vector<vector<int>> newBoard;
  if (board) {
    while (getline(board, line)) {
      newBoard.push_back(ParseLine(line));
    }
  }
  return newBoard;
}

void PrintBoard(vector<vector<int>> board) {
  for (vector<int> v : board) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
}

int main() {

  PrintBoard(ReadBoardFile("./1.board"));

  return 0;
}
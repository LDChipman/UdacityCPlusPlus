#include <iostream>
#include <string>
using std::cout;
using std::string;

void DoubleString(string &value) { value = value + " " + value; }

int main() {
  string s = "Hello";
  cout << "The string s is: " << s << "\n";
  DoubleString(s);
  cout << "The string s is now: " << s << "\n";
}
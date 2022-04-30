#include <iostream>

using std::cout;

int main() {
  int i = 1;
  int c = i++;

  cout << "Post Increment Example: \n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n\n";

  i = 1;
  c = ++i;

  cout << "Pre Increment Example: \n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n\n";

  i = 1;
  c = i--;

  cout << "Post Decrement Example: \n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n\n";

  i = 1;
  c = --i;

  cout << "Pre Decrement Example: \n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n\n";

  return 0;
}
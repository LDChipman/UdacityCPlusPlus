#include <assert.h>

template <typename Type> Type average(Type t1, Type t2) {
  return (t1 + t2) / 2;
}

int main() { assert(average(2.0, 5.0) == 3.5); }
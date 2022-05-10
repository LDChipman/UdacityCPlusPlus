#include <assert.h>

// TODO: Declare a generic, templatized function Max()
template <typename Type> Type Max(Type t1, Type t2) {
  return t1 > t2 ? t1 : t2;
}

int main() {
  assert(Max(10, 50) == 50);
  assert(Max(5.7, 1.436246) == 5.7);
}
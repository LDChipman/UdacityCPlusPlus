#include <assert.h>

template <typename Type> Type Product(Type t1, Type t2) { return t1 * t2; }

int main() { assert(Product<int>(10, 2) == 20); }
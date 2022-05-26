#include <iostream>
#include <memory>
#include <string>

void f1(std::unique_ptr<std::string> unique_ptr) { std::cout << *unique_ptr; }

void f2(std::shared_ptr<std::string> shared_ptr) {
  if (shared_ptr.use_count() == 2) {
    std::cout << *shared_ptr;
  }
}

void f3(std::weak_ptr<std::string> weak_ptr) {
  if (auto shared_ptr = weak_ptr.lock()) {
    std::cout << *shared_ptr << "\n";
  } else {
    std::cout << "weak pointer is expired\n";
  }
}

int main() {
  // create resources to move around
  auto unique_str = std::make_unique<std::string>("Learn ");
  auto shared_str_1 = std::make_shared<std::string>("Coding ");
  auto shared_str_2 = std::make_shared<std::string>("with Udacity!");

  f1(std::move(unique_str));

  f2(shared_str_1);

  // Pass a weak ptr by value and create a shared ptr from it to use it
  std::weak_ptr<std::string> weak_ptr_1;
  weak_ptr_1 = shared_str_2;
  f3(weak_ptr_1);

  // Pass a weak ptr by value after the shared ptr has expired
  std::weak_ptr<std::string> weak_ptr_2;
  {
    auto shared_str_3 = std::make_shared<std::string>("without Udacity");
    weak_ptr_2 = shared_str_3;
  }
  f3(weak_ptr_2);
}
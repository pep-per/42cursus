#include "iter.hpp"

int main() {
  const int arr[] = {1, 2, 3, 4, 5};
  ::iter(arr, 5, f<const int>);
  std::cout << std::endl;
  const char arr2[] = "Happy!";
  ::iter(arr2, 6, f<const char>);
  return 0;
}
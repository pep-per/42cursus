#include "Serializer.hpp"

int main() {
  Data data1;
  data1.s1 = "Yogurt";
  data1.n = 4242;
  data1.s2 = "Icecream";

  uintptr_t raw = Serializer::serialize(&data1);
  Data* data2 = Serializer::deserialize(raw);

  // compare data1(original), data2
  std::cout << data1 << std::endl;
  std::cout << *data2 << std::endl;
  return 0;
}
#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& obj) { *this = obj; }

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& obj) {
  if (this != &obj) {
  }
  return *this;
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

std::ostream& operator<<(std::ostream& out, const Data& obj) {
  out << "string s1 : " << obj.s1 << std::endl;
  out << "int n : " << obj.n << std::endl;
  out << "string s2 : " << obj.s2 << std::endl;
  return out;
}
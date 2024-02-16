#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
 private:
  T* arr_;
  unsigned int size_;

 public:
  Array();
  Array(unsigned int n);
  Array(const Array& obj);
  ~Array();
  Array& operator=(const Array& obj);
  unsigned int size() const;
  T& operator[](unsigned int n);
  const T& operator[](unsigned int n) const;
};

#include "Array.tpp"

#endif
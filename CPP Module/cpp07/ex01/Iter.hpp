#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(const T *arr, const int len, const Func f) {
  for (int i = 0; i < len; i++) {
    f(arr[i]);
  }
}

template <typename T>
void f(const T &t) {
  T tmp = t + 1;
  std::cout << tmp << " ";
}

template <>
void f(const char &c) {
  char tmp;
  if (c >= 'a' && c <= 'z')
    tmp = c + 'A' - 'a';
  else
    tmp = c;
  std::cout << tmp << " ";
}

#endif
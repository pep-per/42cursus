#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *arr, size_t len, Func f) {
  for (size_t i = 0; i < len; i++) {
    f(arr[i]);
  }
}

template <typename T>
void f(T &t) {
  T tmp = t + 1;
  std::cout << tmp << " ";
}

template <>
void f<char>(char &c) {
  char tmp;
  if (c >= 'a' && c <= 'z')
    tmp = c + 'A' - 'a';
  else
    tmp = c;
  std::cout << tmp << " ";
}

template <>
void f<const char>(const char &c) {
  char tmp;
  if (c >= 'a' && c <= 'z')
    tmp = c + 'A' - 'a';
  else
    tmp = c;
  std::cout << tmp << " ";
}

#endif
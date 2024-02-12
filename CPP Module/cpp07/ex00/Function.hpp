#ifndef FUNCTION_HPP
#define FUNCTION_HPP

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b) {
  if (a < b)
    return a;
  else
    return b;
}

template <typename T>
const T &max(const T &a, const T &b) {
  if (a > b)
    return a;
  else
    return b;
}

#endif
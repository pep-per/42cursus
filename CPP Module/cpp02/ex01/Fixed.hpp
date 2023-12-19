#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
 private:
  static const int fraction_;  // 가수
  int exponent_;               // 지수

 public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  Fixed(const Fixed &fixed);
  ~Fixed();
  Fixed &operator=(const Fixed &fixed);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const
};

#endif
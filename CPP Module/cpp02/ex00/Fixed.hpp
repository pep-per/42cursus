#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
 private:
  static const int fraction_;
  int exponent_;

 public:
  Fixed();
  Fixed(const Fixed &fixed);
  ~Fixed();
  Fixed &operator=(const Fixed &fixed);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
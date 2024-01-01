#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
 private:
  static const int numOfFractionBits;
  int rawBits_;

 public:
  Fixed();
  Fixed(const Fixed &fixed);
  ~Fixed();
  Fixed &operator=(const Fixed &fixed);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
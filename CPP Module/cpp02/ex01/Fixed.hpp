#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
 private:
  static const int numOfFractionBits_;
  int rawBits_;

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
  int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
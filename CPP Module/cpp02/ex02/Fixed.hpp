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
  void setRawBits(const int raw);
  float toFloat() const;
  int toInt() const;
  bool operator>(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;
  Fixed &operator++(void);
  const Fixed operator++(int);
  Fixed &operator--(void);
  const Fixed operator--(int);
  Fixed operator+(const Fixed &a) const;
  Fixed operator-(const Fixed &a) const;
  Fixed operator*(const Fixed &a) const;
  Fixed operator/(const Fixed &a) const;
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
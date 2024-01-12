#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;
  Point& operator=(const Point& pt);

 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& pt);
  ~Point();
  const Fixed& getX() const;
  const Fixed& getY() const;
};

#endif
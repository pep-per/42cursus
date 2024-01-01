#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;

 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& pt);
  ~Point();
  Point& operator=(const Point& pt);
  Fixed getX() const;
  Fixed getY() const;
};

#endif
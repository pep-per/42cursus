#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}
Point::Point(const float x, const float y) : x_(x), y_(y) {}
Point::~Point() {}
Point::Point(const Point& pt) : x_(pt.getX()), y_(pt.getY()) {}
Point& Point::operator=(const Point& pt) {
  // This is not allowed because x_ and y_ are const. UB.
  // const_cast<Fixed&>(this->x_) = pt.getX();
  // const_cast<Fixed&>(this->y_) = pt.getY();
  return *this;
}

const Fixed& Point::getX() const { return x_; }
const Fixed& Point::getY() const { return y_; }

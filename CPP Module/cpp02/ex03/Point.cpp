#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}
Point::Point(const float x, const float y) : x_(x), y_(y) {}
Point::~Point() {}
Point::Point(const Point& pt) : x_(pt.getX()), y_(pt.getY()) {}
Point& Point::operator=(const Point& pt) {
  Point* newPt = new Point(pt);
  return *newPt;
}

Fixed Point::getX() const { return x_; }
Fixed Point::getY() const { return y_; }

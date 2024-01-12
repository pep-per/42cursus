#include "Point.hpp"

float vectorProduct(Point const p1, Point const p2, Point const p3) {
  Point v1 = Point((p1.getX() - p3.getX()).toFloat(),
                   (p1.getY() - p3.getY()).toFloat());
  Point v2 = Point((p2.getX() - p3.getX()).toFloat(),
                   (p2.getY() - p3.getY()).toFloat());
  return (v1.getX() * v2.getY() - v1.getY() * v2.getX()).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float d1 = vectorProduct(point, a, b);
  float d2 = vectorProduct(point, b, c);
  float d3 = vectorProduct(point, c, a);

  std::cout << "d1 : " << d1 << std::endl;
  std::cout << "d2 : " << d2 << std::endl;
  std::cout << "d3 : " << d3 << std::endl;

  bool is_plus = d1 > 0 || d2 > 0 || d3 > 0;
  bool is_minus = d1 < 0 || d2 < 0 || d3 < 0;
  return !(is_plus && is_minus) && d1 && d2 && d3;
}
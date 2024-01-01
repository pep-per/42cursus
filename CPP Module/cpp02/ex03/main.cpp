#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  Point a(5, 0);
  Point b(1, 0);
  Point c(3, 4);

  Point p1(2, 1);  // inside
  Point p2(7, 8);  // outside
  Point p3(3, 4);  // on vertex

  if (bsp(a, b, c, p1))
    std::cout << "p1 is in the Triangle" << std::endl;
  else
    std::cout << "p1 is not in the Triangle" << std::endl;
  if (bsp(a, b, c, p2))
    std::cout << "p2 is in the Triangle" << std::endl;
  else
    std::cout << "p2 is not in the Triangle" << std::endl;
  if (bsp(a, b, c, p3))
    std::cout << "p3 is in the Triangle" << std::endl;
  else
    std::cout << "p3 is not in the Triangle" << std::endl;
  return 0;
}
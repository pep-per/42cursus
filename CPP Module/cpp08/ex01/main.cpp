#include "Span.hpp"

int main() {
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    unsigned int n = 10001;
    Span sp1(n);
    std::vector<int> v;
    for (unsigned int i = 0; i < n; i++) {
      v.push_back(i * i);
    }
    sp1.addNumber(v);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    Span sp2(sp1);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
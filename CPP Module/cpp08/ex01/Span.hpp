#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
 private:
  unsigned int n_;
  std::vector<int> v_;
  Span();

 public:
  Span(unsigned int n);
  Span(const Span& obj);
  ~Span();
  Span& operator=(const Span& obj);
  void addNumber(int n);
  void addNumber(const std::vector<int>& v);
  int shortestSpan() const;
  int longestSpan() const;
};

#endif
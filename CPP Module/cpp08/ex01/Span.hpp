#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span {
 private:
  int n_;

 public:
  Span(/* args */);
  Span(const Span& obj);
  ~Span();
  Span& operator=(const Span& obj);
};

#endif

Span::Span(/* args */) {}
Span::Span(const Span& obj) {}
Span::~Span() {}
Span& Span::operator=(const Span& obj) {}

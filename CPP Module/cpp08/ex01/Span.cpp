#include "Span.hpp"

Span::Span() : n_(0) {}

Span::Span(unsigned int n) : n_(n) {}

Span::Span(const Span& obj) { *this = obj; }

Span::~Span() {}

Span& Span::operator=(const Span& obj) {
  if (this != &obj) {
    this->v_.clear();
    addNumber(obj.v_);
    this->n_ = obj.n_;
  }
  return *this;
}

int Span::shortestSpan(void) const {
  if (this->v_.size() < 2) {
    throw std::out_of_range("Not enough elements to calculate span");
  } else {
    std::vector<int> tmp = this->v_;
    std::sort(tmp.begin(), tmp.end());
    long long span = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 2; i++) {
      if (tmp[i + 1] - tmp[i] < span) span = tmp[i + 1] - tmp[i];
    }
    return span;
  }
}

int Span::longestSpan(void) const {
  if (this->v_.size() < 2) {
    throw std::out_of_range("Not enough elements to calculate span");
  } else {
    std::vector<int> tmp = this->v_;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
  }
}

void Span::addNumber(int n) {
  if (this->v_.size() == this->n_)
    throw std::out_of_range("Span is full");
  else
    this->v_.push_back(n);
}

void Span::addNumber(const std::vector<int>& v) {
  if (v.size() > this->n_)
    throw std::out_of_range("Not enough space in Span");
  else
    this->v_.insert(this->v_.end(), v.begin(), v.end());
}
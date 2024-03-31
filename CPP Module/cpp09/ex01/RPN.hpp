#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
 private:
  std::stack<int> stack_;
  RPN(const RPN& obj);
  RPN& operator=(const RPN& obj);

 public:
  RPN();
  ~RPN();
  void calculate(const std::string& str);
};

#endif
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& obj) { *this = obj; }

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& obj) {
  if (this != &obj) {
  }
  return *this;
}

void RPN::calculate(const std::string& str) {
  if (str.empty()) throw std::runtime_error("Error: empty string.");
  std::istringstream iss(str);
  std::string token;
  while (iss >> token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (stack_.size() < 2)
        throw std::runtime_error("Error: not enough arguments.");
      int b = stack_.top();
      stack_.pop();
      int a = stack_.top();
      stack_.pop();
      if (token == "+") {
        stack_.push(a + b);
      } else if (token == "-") {
        stack_.push(a - b);
      } else if (token == "*") {
        stack_.push(a * b);
      } else if (token == "/") {
        if (b == 0)
          throw std::runtime_error("Error: division by zero.");
        else
          stack_.push(a / b);
      }
    } else if (token.size() == 1 && token[0] >= '0' && token[0] <= '9') {
      stack_.push(strtol(token.c_str(), NULL, 10));
    } else {
      throw std::runtime_error("Error");
    }
  }
  if (stack_.size() != 1)
    throw std::runtime_error("Error: invalid expression.");
  else
    std::cout << stack_.top() << std::endl;
}
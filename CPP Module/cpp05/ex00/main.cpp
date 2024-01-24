#include "Bureaucrat.hpp"

int main(void) {
  std::cout << "============== Bureaucrat ==============" << std::endl;
  try {
    Bureaucrat b1("b1", 10);
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooHighException 1========" << std::endl;
  try {
    Bureaucrat b1("b1", 0);
    std::cout << b1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooHighException 2========" << std::endl;
  try {
    Bureaucrat b2("b2", 1);
    std::cout << b2 << std::endl;
    b2.incrementGrade();
    std::cout << b2 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooLowException 1========" << std::endl;
  try {
    Bureaucrat b1("b1", 151);
    std::cout << b1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooLowException 2========" << std::endl;
  try {
    Bureaucrat b2("b2", 150);
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
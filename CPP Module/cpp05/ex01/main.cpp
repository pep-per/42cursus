#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  std::cout << "============ Bureaucrat signs Form ============" << std::endl;
  try {
    Bureaucrat b1("b1", 10);
    std::cout << b1 << std::endl;
    Form f1("f1", 10, 10);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << std::endl;
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << std::endl;
    std::cout << f1 << std::endl;  // This line will not be printed
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "========= Bureaucrat cannot sign Form =========" << std::endl;
  try {
    Bureaucrat b1("b1", 10);
    std::cout << b1 << std::endl;
    Form f2("f2", 9, 10);
    std::cout << f2 << std::endl;
    b1.signForm(f2);
    std::cout << f2 << std::endl;  // This line will not be printed
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooLowException ========" << std::endl;
  try {
    Bureaucrat b1("b1", 10);
    Form f1("f1", 151, 2);
    std::cout << f1 << std::endl;  // This line will not be printed
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "======== GradeTooHighException ========" << std::endl;
  try {
    Bureaucrat b1("b1", 10);
    Form f1("f1", -1, 2);
    std::cout << f1 << std::endl;  // This line will not be printed
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
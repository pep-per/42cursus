#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "============ PresidentialPardonForm ============" << std::endl;
  try {
    Bureaucrat b1("b1", 1);
    PresidentialPardonForm f1("f1");
    b1.signForm(f1);
    b1.executeForm(f1);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "============= RobotomyRequestForm =============" << std::endl;
  try {
    Bureaucrat b2("b2", 1);
    RobotomyRequestForm f2("f2");
    b2.signForm(f2);
    b2.executeForm(f2);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "============ ShrubberyCreationForm ============" << std::endl;
  try {
    Bureaucrat b3("b3", 1);
    ShrubberyCreationForm f3("f3");
    b3.signForm(f3);
    b3.executeForm(f3);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "================ Execution Fail ================" << std::endl;
  try {
    Bureaucrat b4("b4", 26);
    PresidentialPardonForm f4("f4");
    b4.signForm(f4);
    b4.executeForm(f4);  //	this won't be executed
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b4("b4", 6);
    PresidentialPardonForm f4("f4");
    b4.signForm(f4);
    f4.execute(b4);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
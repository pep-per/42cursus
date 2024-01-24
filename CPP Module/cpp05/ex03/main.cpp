#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "============ PresidentialPardonForm ============" << std::endl;
  try {
    Intern i;
    AForm* newForm = i.makeForm("PresidentialPardonForm", "Hermes");
    std::cout << std::endl << *newForm << std::endl;
    delete newForm;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "============= RobotomyRequestForm =============" << std::endl;
  try {
    Intern i;
    AForm* newForm = i.makeForm("RobotomyRequestForm", "Valerie");
    std::cout << std::endl << *newForm << std::endl;
    delete newForm;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "============ ShrubberyCreationForm ============" << std::endl;
  try {
    Intern i;
    AForm* newForm = i.makeForm("ShrubberyCreationForm", "Xavier");
    std::cout << std::endl << *newForm << std::endl;
    delete newForm;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "================ Execution Fail ================" << std::endl;
  try {
    Intern i;
    AForm* newForm = i.makeForm("SomeForm", "Tethys");
    std::cout << std::endl << *newForm << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
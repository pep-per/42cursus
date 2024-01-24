#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) { (void)obj; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
  if (this != &obj) {
  }
  return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
  std::string formNames[3] = {PresidentialPardonForm(target).getName(),
                              RobotomyRequestForm(target).getName(),
                              ShrubberyCreationForm(target).getName()};
  int i;
  for (i = 0; i < 3; i++) {
    if (formNames[i] == name) break;
  }
  switch (i) {
    case 0:
      std::cout << "Intern creates " << name << std::endl;
      return new PresidentialPardonForm(target);
    case 1:
      std::cout << "Intern creates " << name << std::endl;
      return new RobotomyRequestForm(target);
    case 2:
      std::cout << "Intern creates " << name << std::endl;
      return new ShrubberyCreationForm(target);
    default:
      throw Intern::InvalidFormNameException();
  }
}

const char* Intern::InvalidFormNameException::what() const throw() {
  return "Error : Invalid form name";
}
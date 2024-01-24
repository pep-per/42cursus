#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& obj);
  ~Intern();
  Intern& operator=(const Intern& obj);
  AForm* makeForm(std::string name, std::string target);
  class InvalidFormNameException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

 public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& obj);
  ~ShrubberyCreationForm();
  void execute(Bureaucrat const& executor) const;
};

#endif
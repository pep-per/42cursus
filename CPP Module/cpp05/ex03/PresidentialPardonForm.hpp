#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  PresidentialPardonForm();
  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

 public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& obj);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const& executor) const;
};

#endif
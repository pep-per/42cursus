#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();
  RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& obj);
  ~RobotomyRequestForm();
  void execute(Bureaucrat const& executor) const;
};

#endif
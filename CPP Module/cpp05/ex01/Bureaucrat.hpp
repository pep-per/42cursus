#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;
  Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& obj);

 public:
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& obj);
  ~Bureaucrat();
  const std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(Form& form);
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class CannotSignException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
#ifndef FORM_HPP
#define FORM_HPP

#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string name_;
  bool beSigned_;
  const int gradeToSign_;
  const int gradeToExecute_;
  Form();
  Form& operator=(const Form& obj);

 public:
  Form(const std::string name, int gradeToSign, int gradeToExecute);
  Form(const Form& obj);
  ~Form();
  const std::string getName() const;
  bool getBeSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(Bureaucrat& bureaucrat);
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class AlreaySignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
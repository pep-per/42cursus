#ifndef AFORM_HPP
#define AFORM_HPP

#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string name_;
  bool beSigned_;
  const int gradeToSign_;
  const int gradeToExecute_;
  const std::string target_;
  AForm();
  AForm& operator=(const AForm& obj);

 public:
  AForm(const std::string name, int gradeToSign, int gradeToExecute,
        std::string target);
  AForm(const AForm& obj);
  virtual ~AForm();
  const std::string getName() const;
  bool getBeSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  std::string getTarget() const;
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
  class CannotExecuteException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class NotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  virtual void execute(Bureaucrat const& executor) const = 0;
  void checkGrade(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
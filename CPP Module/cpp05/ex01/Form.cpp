#include "Form.hpp"

Form::Form()
    : name_(""), beSigned_(false), gradeToSign_(150), gradeToExecute_(150) {}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name_(name),
      beSigned_(false),
      gradeToSign_(gradeToSign),
      gradeToExecute_(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& obj)
    : name_(obj.name_),
      beSigned_(obj.beSigned_),
      gradeToSign_(obj.gradeToSign_),
      gradeToExecute_(obj.gradeToExecute_) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
  if (this != &obj) {
  }
  return *this;
}

const std::string Form::getName() const { return this->name_; }

bool Form::getBeSigned() const { return this->beSigned_; }

int Form::getGradeToSign() const { return this->gradeToSign_; }

int Form::getGradeToExecute() const { return this->gradeToExecute_; }

void Form::beSigned(Bureaucrat& bureaucrat) {
  if (this->beSigned_) {
    throw Form::AlreaySignedException();
  } else if (bureaucrat.getGrade() > this->gradeToSign_) {
    throw Form::GradeTooHighException();
  } else {
    this->beSigned_ = true;
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade of Form is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade of Form is too low";
}

const char* Form::AlreaySignedException::what() const throw() {
  return "Form is already signed";
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
  out << std::boolalpha;
  out << "[ " << obj.getName() << " ]" << std::endl
      << "Is signed : " << obj.getBeSigned() << std::endl
      << "Grade to sign : " << obj.getGradeToSign() << std::endl
      << "Grade to execute : " << obj.getGradeToExecute() << std::endl;
  out << std::noboolalpha;
  return out;
}
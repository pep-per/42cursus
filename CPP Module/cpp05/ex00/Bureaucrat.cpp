#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade_ = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
    : name_(obj.name_), grade_(obj.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
  if (this == &obj) {
  }
  return *this;
}

const std::string Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::incrementGrade() {
  if (this->grade_ - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else {
    this->grade_--;
  }
}

void Bureaucrat::decrementGrade() {
  if (this->grade_ + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    this->grade_++;
  }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return out;
}
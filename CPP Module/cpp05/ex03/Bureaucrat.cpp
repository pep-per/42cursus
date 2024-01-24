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
  return "Grade of Bureaucrat is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade of Bureaucrat is too low";
}

const char* Bureaucrat::CannotSignException::what() const throw() {
  return "Sign is failed";
}

const char* Bureaucrat::CannotExecuteException::what() const throw() {
  return "Execution is failed";
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
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
  return out;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
    throw Bureaucrat::CannotSignException();
  }
}

void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
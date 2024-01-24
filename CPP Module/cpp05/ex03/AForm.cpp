#include "AForm.hpp"

AForm::AForm()
    : name_(""),
      beSigned_(false),
      gradeToSign_(150),
      gradeToExecute_(150),
      target_("") {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute,
             std::string target)
    : name_(name),
      beSigned_(false),
      gradeToSign_(gradeToSign),
      gradeToExecute_(gradeToExecute),
      target_(target) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm& obj)
    : name_(obj.name_),
      beSigned_(obj.beSigned_),
      gradeToSign_(obj.gradeToSign_),
      gradeToExecute_(obj.gradeToExecute_),
      target_(obj.target_) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& obj) {
  if (this != &obj) {
  }
  return *this;
}

const std::string AForm::getName() const { return this->name_; }

bool AForm::getBeSigned() const { return this->beSigned_; }

int AForm::getGradeToSign() const { return this->gradeToSign_; }

int AForm::getGradeToExecute() const { return this->gradeToExecute_; }

std::string AForm::getTarget() const { return this->target_; }

void AForm::beSigned(Bureaucrat& bureaucrat) {
  if (this->beSigned_) {
    throw AForm::AlreaySignedException();
  } else if (bureaucrat.getGrade() > this->gradeToSign_) {
    throw AForm::GradeTooHighException();
  } else {
    this->beSigned_ = true;
  }
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade of Form is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade of Form is too low";
}

const char* AForm::AlreaySignedException::what() const throw() {
  return "Form is already signed";
}

const char* AForm::CannotExecuteException::what() const throw() {
  return "Execution is failed";
}

const char* AForm::NotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
  out << std::boolalpha;
  out << "[ " << obj.getName() << " ]" << std::endl
      << "Is signed : " << obj.getBeSigned() << std::endl
      << "Grade to sign : " << obj.getGradeToSign() << std::endl
      << "Grade to execute : " << obj.getGradeToExecute() << std::endl
      << "Target : " << obj.getTarget() << std::endl;
  out << std::noboolalpha;
  return out;
}

void AForm::checkGrade(Bureaucrat const& executor) const {
  if (!this->beSigned_) {
    throw AForm::NotSignedException();
  } else if (executor.getGrade() > this->gradeToExecute_) {
    throw AForm::GradeTooHighException();
  }
}
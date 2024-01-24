#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& obj)
    : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute(),
            obj.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& obj) {
  if (this != &obj) {
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  try {
    AForm::checkGrade(executor);
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
              << std::endl;
  } catch (const std::exception& e) {
    std::cout << executor.getName() << " couldn't execute " << getName()
              << ", because " << e.what() << std::endl;
    throw AForm::CannotExecuteException();
  }
}
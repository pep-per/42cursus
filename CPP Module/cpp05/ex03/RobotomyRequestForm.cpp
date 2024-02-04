#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
  srand((unsigned int)time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
    : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute(),
            obj.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& obj) {
  if (this != &obj) {
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  try {
    AForm::checkGrade(executor);
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2 == 0) {
      std::cout << getTarget() << " has been robotomized successfully!"
                << std::endl;
    } else {
      std::cout << getTarget() << " robotomization failed" << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << executor.getName() << " couldn't execute " << getName()
              << ", because " << e.what() << std::endl;
    throw AForm::CannotExecuteException();
  }
}
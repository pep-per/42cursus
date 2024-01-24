#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
    : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute(),
            obj.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& obj) {
  if (this != &obj) {
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  try {
    AForm::checkGrade(executor);
    std::ofstream ofs(getTarget() + "_shrubbery");
    ofs << std::endl;
    ofs << "                                                     ."
        << std::endl;
    ofs << "                                          .         ;  "
        << std::endl;
    ofs << "             .              .              ;%     ;;   "
        << std::endl;
    ofs << "               ,           ,                :;%  %;   "
        << std::endl;
    ofs << "                :         ;                   :;%;'     .,   "
        << std::endl;
    ofs << "       ,.        %;     %;            ;        %;'    ,;"
        << std::endl;
    ofs << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'"
        << std::endl;
    ofs << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' "
        << std::endl;
    ofs << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    ofs << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    ofs << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    ofs << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
    ofs << "                  `@%:.  :;%.         ;@@%;'   " << std::endl;
    ofs << "                    `@%.  `;@%.      ;@@%;         " << std::endl;
    ofs << "                      `@%%. `@%%    ;@@%;        " << std::endl;
    ofs << "                        ;@%. :@%%  %@@%;       " << std::endl;
    ofs << "                          %@bd%%%bd%%:;     " << std::endl;
    ofs << "                            #@%%%%%:;;" << std::endl;
    ofs << "                            %@@%%%::;" << std::endl;
    ofs << "                            %@@@%(o);  . '         " << std::endl;
    ofs << "                            %@@@o%;:(.,'         " << std::endl;
    ofs << "                        `.. %@@@o%::;         " << std::endl;
    ofs << "                           `)@@@o%::;         " << std::endl;
    ofs << "                            %@@(o)::;        " << std::endl;
    ofs << "                           .%@@@@%::;         " << std::endl;
    ofs << "                           ;%@@@@%::;.          " << std::endl;
    ofs << "                          ;%@@@@%%:;;;. " << std::endl;
    ofs << "                      ...;%@@@@@%%:;;;;,..    " << std::endl;
    ofs << std::endl;
  } catch (const std::exception& e) {
    std::cout << executor.getName() << " couldn't execute " << getName()
              << ", because " << e.what() << std::endl;
    throw AForm::CannotExecuteException();
  }
}
#include "Brain.hpp"

Brain::Brain() : ideas_() {
  std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
  std::cout << "Brain Copy Constructor called" << std::endl;
  *this = obj;
}

Brain::~Brain() { std::cout << "Brain Destructor called" << std::endl; }

Brain& Brain::operator=(const Brain& obj) {
  std::cout << "Brain Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->setIdeas(obj.getIdeas());
  }
  return *this;
}

const std::string& Brain::getIdeas() const { return this->ideas_[0]; }

void Brain::setIdeas(const std::string& str) {
  if (str.size() > 100) return;
  this->ideas_->clear();
  this->ideas_->append(str);
}
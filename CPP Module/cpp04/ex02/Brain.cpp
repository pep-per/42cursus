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
  if (this != &obj) {
    for (int i = 0; i < 100; i++) {
      this->setIdeas(obj.getIdeas(i), i);
    }
  }
  std::cout << "Brain Copy Assignment Operator called" << std::endl;
  return *this;
}

std::string Brain::getIdeas(int i) const { return this->ideas_[i]; }

void Brain::setIdeas(std::string str, int i) { this->ideas_[i] = str; }
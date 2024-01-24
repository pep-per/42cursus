#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain();
  Brain(const Brain& obj);
  ~Brain();
  Brain& operator=(const Brain& obj);
  std::string getIdeas(int i) const;
  void setIdeas(std::string str, int i);
};

#endif